#!/bin/bash
wget -P /tmp https://github.com/RichardMushunje/alx-low_level_programming/raw/master/0x18-dynamic_libraries/mylib.so
export LD_PRELOAD=/tmp/mylib.so
