#pragma once
#include <iostream>
#include <FL/Fl_File_Chooser.H>
#include <FL/fl_ask.H>
#include <string>

#define log(x) std::cout << x << "\n"

bool choose_file(std::string &out)
{
    char *path = fl_file_chooser("Select a file", "*", ".");

    if (path == NULL)
        return false;

    out = path;
    return true;
}

void alert(const char* msg)
{
    log(msg);
    fl_alert(msg);
}

void info(const char* msg)
{
    log(msg);
    fl_message(msg);
}