#!/bin/bash

git clone --recursive https://github.com/corvusoft/restbed.git
mkdir restbed/build
cd restbed/build
cmake -DBUILD_SSL=NO ..
make -j5 install
make test
