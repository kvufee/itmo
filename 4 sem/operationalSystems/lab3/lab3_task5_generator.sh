#!/bin/bash

mkfifo pipe

while true; do
    read line
    echo "$line" > pipe
    if [ "$line" == "QUIT" ]; then
        echo "GENERATOR STOP"
        break
    fi
done

