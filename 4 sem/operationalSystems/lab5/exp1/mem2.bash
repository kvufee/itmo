#!/bin/bash

array=()
counter=0
while true; do
    array+=({1..10})
    let counter++
    if (( counter % 100000 == 0 )); then
        echo "arr size: ${#array[@]}" >> report2.log
    fi
done
