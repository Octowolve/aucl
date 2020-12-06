#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include "main.h"
#include "hooks.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)initialize, hModule, NULL, NULL);
        break;
    }
    case DLL_PROCESS_DETACH: {
        hooks::release();
#ifdef DEBUG
        close_console();
#endif // DEBUG
        FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
        break;
    }
        break;
    }
    return TRUE;
}

