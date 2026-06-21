#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

const char* ffConnectDisplayServerImpl(void* result) { (void) result; return "Unsupported on iOS"; }

const char* ffDetectBattery(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectBios(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectBluetooth(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectBluetoothRadio(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectBoard(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectBootmgr(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectBrightness(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectCPUImpl(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectCamera(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectDNS(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectFontImpl(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectGPUImpl(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectGamepad(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectHost(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectInitSystem(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectKeyboard(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectLocalIps(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectMediaImpl(void* result, bool saveCover) { (void) result; (void) saveCover; return "Unsupported on iOS"; }
const char* ffDetectMouse(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectPhysicalDisk(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }
const char* ffDetectPhysicalMemory(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectPowerAdapter(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectShell(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectSound(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectTPM(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectTerminal(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectTerminalFontPlatform(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectWMPlugin(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectWMVersion(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectWallpaper(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffDetectWifi(void* result) { (void) result; return "Unsupported on iOS"; }

const char* ffDiskIOGetIoCounters(void* result) { (void) result; return "Unsupported on iOS"; }
bool ffKmodLoaded(const char* name) { (void) name; return false; }
const char* ffNetIOGetIoCounters(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffNetifGetDefaultRouteImplV4(void* result) { (void) result; return "Unsupported on iOS"; }
const char* ffNetifGetDefaultRouteImplV6(void* result) { (void) result; return "Unsupported on iOS"; }

void* ffDetectOpenCL(void) { return NULL; }
const char* ffDetectOpenGL(void* options, void* result) { (void) options; (void) result; return "Unsupported on iOS"; }

int ffProcessSpawn(void* command, void* options) { (void) command; (void) options; return -1; }
bool ffProcessReadOutput(void* command, void* options, void* result) { (void) command; (void) options; (void) result; return false; }
