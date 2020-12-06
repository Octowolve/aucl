#include "main.h"
#include "utils.h"
#include "hooks.h"
#include <iostream>
#include <chrono>
#include <thread>
extern const LPCWSTR LOG_FILE = L"log.txt";

int initialize() {
#ifdef DEBUG
	new_console();
#endif // DEBUG

	if (!hooks::initialize()) {
		std::cout << "Couldn't initialize hooks!\n";
		return 1;
	}

	while (!GetAsyncKeyState(VK_END)) 
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

	return 0;
}