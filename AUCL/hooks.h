#pragma once
#include "minhook/minhook.h"
#include "utils.h"
#include "structs.h"

#include <d3d11.h>
#include <dxgi.h>
#include "il2cpp.h"
namespace hooks {
	bool initialize();
	void release();
	void get_present();

	namespace ChatController_AddChat {
		using orig = void (__cdecl*)(void* __this, void* sourcePlayer, Il2cppString* chatText);
		void __cdecl hook(void* __this, BHHCHKFKPOE_o* sourcePlayer, Il2cppString* chatText);
	}

	namespace Present {
		using orig = HRESULT(__stdcall*) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		HRESULT __stdcall hook(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	}

}