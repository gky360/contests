#!/bin/bash

set -eux

p=$1
d=$2

git add $p && git commit -m "$(cat $p/Main.cpp | head -2 | tail -1)" --date "$d"
