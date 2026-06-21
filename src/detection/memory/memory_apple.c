#include "memory.h"
#include "common/settings.h"

#include <mach/mach.h>
#include <sys/sysctl.h>
#include <stdint.h>

const char* ffDetectMemory(FFMemoryResult* result)
{
    uint64_t total = 0;
    size_t size = sizeof(total);

    if (sysctlbyname("hw.memsize", &total, &size, NULL, 0) != 0 || total == 0)
        return "sysctl hw.memsize failed";

    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    vm_statistics64_data_t vmstat;

    if (host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t)&vmstat, &count) != KERN_SUCCESS)
        return "host_statistics64 failed";

    vm_size_t pageSize = 0;
    host_page_size(mach_host_self(), &pageSize);

    uint64_t freeMem =
        ((uint64_t)vmstat.free_count +
         (uint64_t)vmstat.inactive_count) * (uint64_t)pageSize;

    result->bytesTotal = total;
    result->bytesUsed = total > freeMem ? total - freeMem : 0;

    return NULL;
}
