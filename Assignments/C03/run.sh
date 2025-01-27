#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "Usage requires an numerical argument"
    exit 1
fi

make build
./main $@
make clean