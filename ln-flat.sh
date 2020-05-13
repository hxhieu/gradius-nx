#!/bin/bash
cd ./include/flat && ln -s ../../lib/flat/src/*.h . && cd ../..
cd ./source/flat && ln -s ../../lib/flat/src/*.cpp . && cd ../..

