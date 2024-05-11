#!/bin/bash
while true; do
    cpu_usage=$(top -b -n 1 -p 3480 | tail -1 | awk '{print $9}')
    if (( $(echo "$cpu_usage > 10.0" | bc -l) )); then
        kill -STOP 3480
        sleep 5
        kill -CONT 3480
    fi
    sleep 5
done
