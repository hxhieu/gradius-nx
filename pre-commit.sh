#!/bin/bash
find ./include -type f \( -iname \*.h -o -iname \*.hpp \) -not -path "./include/flat*" -exec clang-format -i {} \;
find ./source -type f \( -iname \*.cpp \) -not -path "./source/flat*" -exec clang-format -i {} \;
