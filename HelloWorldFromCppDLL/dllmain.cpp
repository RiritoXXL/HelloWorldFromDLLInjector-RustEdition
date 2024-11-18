// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

DWORD WINAPI Thread() {
    MessageBoxA(0, "Hello World From C++ Code", "HelloWorldFromDLLInjector-RustEdition", MB_OK | MB_ICONASTERISK);
    ExitProcess(1223);
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

