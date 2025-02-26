#!/bin/bash

# if [ "$#" -ne 5 ]; then
#     echo "Usage requires five numerical argument"
#     exit 1
# fi

make all
./coordinator $@
# ./coordinator
make clean