#!/bin/bash

g++ ./garden.cpp \
  -o ./bin/garden.exe \
  -Wall -Werror \
  -D__DEBUG__ -g
