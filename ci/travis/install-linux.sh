#!/usr/bin/env bash

sudo apt update
sudo apt install make
sudo apt install
sudo apt install libboost-dev libboost-program-options-dev

git clone https://github.com/abseil/googletest.git
git submodule update --init
cd googletest
mkdir build       # Create a directory to hold the build output.
cd build
cmake ..  # Generate native build scripts.
make
sudo make install
cd ../..
