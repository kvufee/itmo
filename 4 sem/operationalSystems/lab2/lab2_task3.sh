#!/bin/bash

PROCESS_LIST=$(ps -e -o pid,lstart)

echo "$PROCESS_LIST" | tail -n 1 | awk '{print $1}'
