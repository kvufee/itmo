#!/bin/bash

value=1
mode="add"

function add_value {
    value=$((value + 2))
    echo "Value: $value"
}

function umnoj_value {
    value=$((value * 2))
    echo "Value: $value"
}

function stop {
    echo "HANDLER STOP"
    exit 0
}

trap add_value USR1
trap umnoj_value USR2
trap stop SIGTERM

while true; do
    echo "Wait"
    sleep 3
done
