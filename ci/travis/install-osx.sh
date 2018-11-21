#!/usr/bin/env bash

brew update
brew install make

git clone https://github.com/oktal/pistache.git
git submodule update --init
cd pistache
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
make install

cd ../..

git clone https://github.com/abseil/googletest.git
git submodule update --init
cd googletest
mkdir build       # Create a directory to hold the build output.
cd build
cmake ..  # Generate native build scripts.
make
make install

cd ../..


git clone https://github.com/Tencent/rapidjson.git
git submodule update --init
cd rapidjson
mkdir build
cd build
cmake ..
make
make install
cd ../..