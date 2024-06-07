#!/bin/bash

set -e

MAX=5000
STEP=$((($MAX-300)/$1))

for (( i = 0;i < $1; i++ ))
do
    sox -n -r 44100 -c 1 "$i.wav" synth 0.1 sine $((i*STEP+300))
done
