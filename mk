#!/usr/bin/env bash
# dpw@66ae29f3498d
# 2022-02-14 14:33:42
#

set -eu

[ -d bin ] || mkdir -p bin

g++ -std=c++2a -pthread -lpthread -Wall -o bin/tcp-server *.cpp

