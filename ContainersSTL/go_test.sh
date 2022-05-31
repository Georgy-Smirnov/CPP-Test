#!/bin/bash

clang++ -Wall -Werror -Wextra --std=c++98 -fsanitize=address test.cpp -o test && ./test