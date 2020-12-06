#pragma once
#include <string>

// Helper function to get the module base address
uintptr_t get_base_address();

// rva + base address = pointers
uintptr_t get_absolute_address(uintptr_t relativeAddress);

// Helper function to append text to a file
void log_write(std::string text);

// Helper function to open a new console window and redirect stdout there
void new_console();

//helper function to close the created console
void close_console();

//get the color as a name from its id
void get_color_string(int colorId, char* colorName, size_t bufferSize);
