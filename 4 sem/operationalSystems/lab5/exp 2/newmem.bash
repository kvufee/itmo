#!/bin/bash

array=()
counter=0
N=$1

while (( ${#array[@]} < N )); do
    array+=({1..10})
    let counter++
done
