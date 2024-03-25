#!/bin/bash

set -e

for (( i=0;i<10;i++ ))
do
    sox -n -r 22100 -c 1 "beep$i.wav" synth 0.1 sine $((i*150+400))
done


