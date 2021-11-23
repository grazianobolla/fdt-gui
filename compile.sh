#!/bin/bash
compile_linux="g++ fdt-gui.cpp -o bin/fdt-gui.o -lfltk"
compile_windows="x86_64-w64-mingw32-g++ -static fdt-gui.cpp -o bin/fdt-gui.exe -lfltk -lcomctl32 -lgdi32 -lole32 -luuid -lssp"

if [ "$1" == "run" ];
then
    $compile_linux
    ./bin/fdt-gui.o
fi

if [ "$1" == "windows" ];
then
    $compile_windows
    strip bin/fdt-gui.exe
fi

if [ "$1" == "all" ];
then
    $compile_linux
    $compile_windows
    strip bin/fdt-gui.exe
    strip bin/fdt-gui.o
fi