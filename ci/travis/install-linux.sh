#!/usr/bin/env bash

sudo apt update
sudo apt install make
sudo apt install libboost-all-dev
sudo apt install libpq-dev


git clone https://github.com/jtv/libpqxx
cd libpqxx/
./configure
make -j8
sudo make install
cd ..



git clone https://github.com/abseil/googletest.git
cd googletest/
git submodule update --init
mkdir build
cd build
cmake ..
make -j8
sudo make install
cd ../..
