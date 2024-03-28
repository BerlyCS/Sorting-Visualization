#!/bin/bash

set -e

MAX=3000
STEP=$((($MAX-300)/$1))

for (( i = 0;i < $1; i++ ))
do
    sox -n -r 22100 -c 1 "$i.wav" synth 0.2 sine $((i*150+300))
done
