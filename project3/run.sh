#!/bin/bash

# Compile the code
g++ -g source/project3.cpp -o kSmall.out
# Run the program with test case argument through gdb, then quit.
gdb -q -ex "run y" -ex "quit" ./kSmall.out
