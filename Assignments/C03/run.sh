#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage requires one numerical argument"
    exit 1
fi

make build
./main $@
make clean