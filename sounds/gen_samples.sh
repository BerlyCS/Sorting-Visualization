#!/bin/bash

set -e

for (( i=0;i<10;i++ ))
do
    sox -n -r 44100 -c 2 "beep$i.wav" synth 0.1 sine $((i*100+500))
done
