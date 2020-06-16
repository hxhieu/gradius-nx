#!/bin/bash
find ./source -type f \( -iname \*.cpp -o -iname \*.h -o -iname \*.hpp \) -not -path "./source/flat*" -exec clang-format  --Werror --verbose -i {} \;
