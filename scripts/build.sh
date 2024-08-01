#!/bin/bash

if [ -d "build" ]; then
    rm -rf build
fi

if [ ! -d "cJSON" ]; then
    git clone https://github.com/DaveGamble/cJSON.git
fi

mkdir build

cp -r res build
chmod 644 /build/res

cd build

cmake -DCMAKE_BUILD_TYPE=Debug -DDEBUG=ON ..
make
