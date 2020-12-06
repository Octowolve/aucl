#pragma once
#pragma warning( disable : 4091 )
#include <sstream>
#include <codecvt>

typedef struct Il2cppString
{
    void* klass;
    void* monitor;
    int32_t length;
    char chars[32];
    int getLength()
    {
        return length;
    }
    char* getChars()
    {
        return chars;
    }

    std::string to_utf8() {
        std::u16string u16_string(reinterpret_cast<const char16_t*>(getChars()));
        std::wstring wide_string(u16_string.begin(), u16_string.end());
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
        return convert.to_bytes(wide_string);
    }
};
