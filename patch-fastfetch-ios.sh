#!/bin/sh
set -eu

python3 - <<'PY'
from pathlib import Path

p = Path("CMakeLists.txt")
s = p.read_text()

old = '''if(ANDROID)
    set(LINUX FALSE)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")'''

new = '''option(FASTFETCH_IOS "Build fastfetch for jailbroken iOS/iPadOS" OFF)

if(ANDROID)
    set(LINUX FALSE)
elseif(FASTFETCH_IOS)
    message(STATUS "Fastfetch: jailbroken iOS/iPadOS compatibility enabled")
    set(IOS TRUE CACHE BOOL "..." FORCE)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")'''

s = s.replace(old, new, 1)

bad_sources = [
"src/detection/opencl/opencl.c",
"src/detection/opengl/opengl.c",
"src/detection/opengl/opengl_linux.c",
"src/detection/opengl/opengl_shared.c",
"src/detection/opengl/opengl_apple.c",
"src/common/impl/netif_apple.c",
"src/common/impl/processing_linux.c",
"src/detection/battery/battery_apple.c",
"src/detection/bluetooth/bluetooth_apple.m",
"src/detection/bluetoothradio/bluetoothradio_apple.m",
"src/detection/brightness/brightness_apple.c",
"src/detection/dns/dns_apple.c",
"src/detection/physicaldisk/physicaldisk_apple.c",
"src/detection/diskio/diskio_apple.c",
"src/detection/displayserver/displayserver_apple.c",
"src/detection/font/font_apple.m",
"src/detection/gpu/gpu_apple.c",
"src/detection/gpu/gpu_apple.m",
"src/detection/keyboard/keyboard_apple.c",
"src/detection/localip/localip_linux.c",
"src/detection/gamepad/gamepad_apple.c",
"src/detection/mouse/mouse_apple.c",
"src/detection/netio/netio_apple.c",
"src/detection/poweradapter/poweradapter_apple.c",
"src/detection/sound/sound_apple.c",
"src/detection/wifi/wifi_apple.m",
"src/detection/wm/wm_apple.m",
"src/detection/camera/camera_apple.m",
]

guard = '''
if(FASTFETCH_IOS)
    list(REMOVE_ITEM LIBFASTFETCH_SRC
{items}
    )
endif()

'''.format(items="\n".join(f"        {x}" for x in bad_sources))

s = s.replace("add_library(libfastfetch", guard + "add_library(libfastfetch", 1)
p.write_text(s)

# system() unavailable on iOS
p = Path("src/options/general.c")
s = p.read_text()
s = s.replace(
'''            if (system(unsafe_yyjson_get_str(val)) < 0) {
                return "Failed to execute preRun command";
            }''',
'''            /* iOS: system() unavailable, ignore preRun */
            (void) val;'''
)
p.write_text(s)

# wordexp unavailable on iOS
p = Path("src/common/impl/io_unix.c")
s = p.read_text()
if "#if FF_HAVE_WORDEXP" in s:
    start = s.index("#if FF_HAVE_WORDEXP")
    middle = s.index("#else", start)
    end = s.index("#endif", middle) + len("#endif")
    fallback = s[middle + len("#else"):s.index("#endif", middle)]
    s = s[:start] + fallback + s[end:]
p.write_text(s)
PY

rm -rf build
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/var/jb/usr/local \
  -DFASTFETCH_IOS=ON

cmake --build build --target fastfetch -- -k -j2
