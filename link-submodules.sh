# Just link the libs and build it natively
#!/bin/bash
cd ./include/flat && ln -s ../../lib/flat/src/*.h . && cd ../..
cd ./source/flat && ln -s ../../lib/flat/src/*.cpp . && cd ../..
cd ./include/wink && ln -s ../../lib/wink-signals/wink/* . && cd ../..

