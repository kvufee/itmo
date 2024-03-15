#!/bin/bash

FILE_NAME="pid.txt"

PROCESS_LIST=$(ps -eo pid,comm | grep "/sbin/")

echo "$PROCESS_LIST" | awk '{print $1}' > $FILE_NAME

