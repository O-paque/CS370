# Author 
Tyler Seefeldt

# File Descriptions

## Coordinator.c: Forks a child process while creating pipes and shared memory 
segments for IPC. Passes along command line arguments to child processes and 
waits for results.

## Checker.c: Reads the address of shared memory passed to it by the pipe from 
its parent. Takes the two command line arguments passed to it and checks if the dividend would
have a remainder with the current divisor. If remainder is true, writes 0 to the
shared memory segment, otherwise writes 1.

## Makefile: A Makefile made using information provided in the linked Infospaces
video ending in 277.

## README.txt: This file.