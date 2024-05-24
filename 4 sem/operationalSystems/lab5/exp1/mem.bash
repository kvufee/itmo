#!/bin/bash

array=()
counter=0
N=$1
while true; do
    array+=({1..10})
    let counter++
    if (( counter % 100000 == 0 )); then
        echo "arr size: ${#array[@]}" >> report.log
    fi
done
