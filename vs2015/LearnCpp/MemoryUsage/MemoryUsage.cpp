// MemoryUsage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"
#include <sysinfoapi.h>
#include <iostream>
#include "psapi.h"

// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

void PrintMemoryInfo(DWORD processID)
{
    HANDLE hProcess;
    PROCESS_MEMORY_COUNTERS pmc;

    // Print the process identifier.

    printf("\nProcess ID: %u\n", processID);

    // Print information about the memory usage of the process.

    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
        PROCESS_VM_READ,
        FALSE, processID);
    if (NULL == hProcess)
        return;

    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
    {
        printf("\tPageFaultCount: 0x%08X\n", pmc.PageFaultCount);
        printf("\tPeakWorkingSetSize: 0x%08X\n",
            pmc.PeakWorkingSetSize);
        printf("\tWorkingSetSize: 0x%08X\n", pmc.WorkingSetSize);
        printf("\tQuotaPeakPagedPoolUsage: 0x%08X\n",
            pmc.QuotaPeakPagedPoolUsage);
        printf("\tQuotaPagedPoolUsage: 0x%08X\n",
            pmc.QuotaPagedPoolUsage);
        printf("\tQuotaPeakNonPagedPoolUsage: 0x%08X\n",
            pmc.QuotaPeakNonPagedPoolUsage);
        printf("\tQuotaNonPagedPoolUsage: 0x%08X\n",
            pmc.QuotaNonPagedPoolUsage);
        printf("\tPagefileUsage: 0x%08X\n", pmc.PagefileUsage);
        printf("\tPeakPagefileUsage: 0x%08X\n",
            pmc.PeakPagefileUsage);
    }

    CloseHandle(hProcess);
}

int main()
{
    PrintMemoryInfo(GetCurrentProcessId());

    return 0;
}

