#!/usr/bin/env bash

sudo apt update
sudo apt install make

git clone https://github.com/oktal/pistache.git
git submodule update --init
cd pistache
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install

cd

git clone https://github.com/abseil/googletest.git
cd googletest
mkdir build       # Create a directory to hold the build output.
cd build
cmake ..  # Generate native build scripts.
make
sudo make install

cd