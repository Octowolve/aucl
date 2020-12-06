#include "utils.h"
#include <windows.h>
#include <time.h>

// Log file location
extern const LPCWSTR LOG_FILE;
// Helper function to get the module base address
uintptr_t get_base_address() {
	return (uintptr_t)GetModuleHandleA("GameAssembly.dll");
}

uintptr_t get_absolute_address(uintptr_t relativeAddr)
{
	return  (get_base_address() + relativeAddr);
}

// Helper function to append text to a file
void log_write(std::string text) {
	HANDLE hfile = CreateFileW(LOG_FILE, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hfile == INVALID_HANDLE_VALUE)
		MessageBoxW(0, L"Could not open log file", 0, 0);

	DWORD written;
	WriteFile(hfile, text.c_str(), (DWORD)text.length(), &written, NULL);
	WriteFile(hfile, "\r\n", 2, &written, NULL);
	CloseHandle(hfile);
}

// Helper function to open a new console window and redirect stdout there
void new_console() {
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
}

void close_console() {
	fclose(reinterpret_cast<FILE*>(stdout));
	FreeConsole();
}

void get_color_string(int colorId, char* colorName, size_t bufferSize)
{
	switch (colorId) {
	case 0:
		strcpy_s(colorName, bufferSize, "Red");
		break;
	case 1:
		strcpy_s(colorName, bufferSize, "Blue");
		break;
	case 2:
		strcpy_s(colorName, bufferSize, "Green");
		break;
	case 3:
		strcpy_s(colorName, bufferSize, "Pink");
		break;
	case 4:
		strcpy_s(colorName, bufferSize, "Orange");
		break;
	case 5:
		strcpy_s(colorName, bufferSize, "Yellow");
		break;
	case 6:
		strcpy_s(colorName, bufferSize, "Black");
		break;
	case 7:
		strcpy_s(colorName, bufferSize, "White");
		break;
	case 8:
		strcpy_s(colorName, bufferSize, "Purple");
		break;
	case 9:
		strcpy_s(colorName, bufferSize, "Brown");
		break;
	case 10:
		strcpy_s(colorName, bufferSize, "Cyan");
		break;
	case 11:
		strcpy_s(colorName, bufferSize, "Lime");
		break;
	default:
		strcpy_s(colorName, bufferSize, "Unknown Color");
	}
}
