#!/usr/bin/env bash

sudo apt update
sudo apt install make
sudo apt install libboost-all-dev
sudo apt install postgresql-all


git clone https://github.com/jtv/libpqxx
cd libpqxx/
mkdir build
cd build/
cmake ..
make -j8
sudo make install
cd ../..



git clone https://github.com/abseil/googletest.git
git submodule update --init
cd googletest/
mkdir build       # Create a directory to hold the build output.
cd build
cmake ..  # Generate native build scripts.
make -j8
sudo make install
cd ../..
