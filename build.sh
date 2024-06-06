#!/bin/bash

read -p "Building for the first time? [y/N]: " first_time
read -p "Build for Debug or Release? [Debug/Release/Both]: " build_type

echo

if [[ "$build_type" == "Debug" ]]
then
    if [[ "$first_time" =~ ^[Yy]$ ]]
    then
        echo "Configuring CMake for Linux Debug configuration..."
        cmake -S . -B build/linux_x64-Debug -DBUILD_TYPE=true -G Ninja

        echo

        echo "Configuring CMake for Windows Debug configuration..."
        cmake -S . -B build/windows_x64-Debug -DBUILD_TYPE=true -DCMAKE_TOOLCHAIN_FILE=~/SmoollDev/Toolchains/toolchain-x86_64-w64-mingw32.cmake -G Ninja

        echo
    fi

    echo "Building linux_x64-Debug..."
    cmake --build build/linux_x64-Debug --parallel

    echo

    echo "Building windows_x64-Debug..."
    cmake --build build/windows_x64-Debug --parallel
elif [[ "$build_type" == "Release" ]]
then
    if [[ "$first_time" =~ ^[Yy]$ ]]
    then
        echo "Configuring CMake for Linux Release configuration..."
        cmake -S . -B build/linux_x64-Release -DBUILD_TYPE=false -G Ninja

        echo

        echo "Configuring CMake for Windows Release configuration..."
        cmake -S . -B build/windows_x64-Release -DBUILD_TYPE=false -DCMAKE_TOOLCHAIN_FILE=~/SmoollDev/Toolchains/toolchain-x86_64-w64-mingw32.cmake -G Ninja

        echo
    fi

    echo "Building linux_x64-Release..."
    cmake --build build/linux_x64-Release --parallel

    echo

    echo "Building window_x64-Release..."
    cmake --build build/windows_x64-Release --parallel
elif [[ "$build_type" == "Both" ]]
then
    if [[ "$first_time" =~ ^[Yy]$ ]]
    then
        echo "Configuring CMake for Linux Debug configuration..."
        cmake -S . -B build/linux_x64-Debug -DBUILD_TYPE=true -G Ninja

        echo

        echo "Configuring CMake for Linux Release configuration..."
        cmake -S . -B build/linux_x64-Release -DBUILD_TYPE=false -G Ninja

        echo

        echo "Configuring CMake for Windows Debug configuration..."
        cmake -S . -B build/windows_x64-Debug -DBUILD_TYPE=true -DCMAKE_TOOLCHAIN_FILE=~/SmoollDev/Toolchains/toolchain-x86_64-w64-mingw32.cmake -G Ninja

        echo

        echo "Configuring CMake for Windows Release configuration..."
        cmake -S . -B build/windows_x64-Release -DBUILD_TYPE=false -DCMAKE_TOOLCHAIN_FILE=~/SmoollDev/Toolchains/toolchain-x86_64-w64-mingw32.cmake -G Ninja

        echo
    fi

    echo "Building linux_x64-Debug..."
    cmake --build build/linux_x64-Debug --parallel

    echo

    echo "Building linux_x64-Release..."
    cmake --build build/linux_x64-Release --parallel

    echo

    echo "Building windows_x64-Debug..."
    cmake --build build/windows_x64-Debug --parallel

    echo

    echo "Building windows_x64-Release..."
    cmake --build build/windows_x64-Release --parallel
fi

echo
read -p "Building successful! Would you like to run the application? [y/N]: " should_run

if [[ "$should_run" =~ ^[Yy]$ ]]
then
    echo "Running pong..."
    echo
    ./build/linux_x64-Debug/pong
elif [[ "$should_run" =~ ^[Nn]$ ]] || [[ "$should_run" == "" ]]
then
    echo
    echo "Exiting..."
fi
