#!/bin/bash

g++ ./garden.cpp \
  -o garden.exe \
  -Wall -Werror \
  -D__DEBUG__ -g
