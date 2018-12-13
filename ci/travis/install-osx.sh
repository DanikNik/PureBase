#!/usr/bin/env bash

brew update
brew install make
brew install libpq libpqxx
brew install boost

git clone https://github.com/abseil/googletest.git
git submodule update --init
cd googletest
mkdir build       # Create a directory to hold the build output.
cd build
cmake ..  # Generate native build scripts.
make
make install

cd ../..
