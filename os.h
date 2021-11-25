#pragma once

enum OS{LINUX, WINDOWS, OTHER};

OS get_os()
{
    #ifdef _WIN32
        return WINDOWS;
    #elif _WIN64
        return WINDOWS;
    #elif __linux__
        return LINUX;
    #else
        return OTHER;
    #endif
}