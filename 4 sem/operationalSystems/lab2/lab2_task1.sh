#!/bin/bash

FILE_NAME="processAmount.txt"

PROCESS_LIST=$(ps -u)

PROCESS_AMOUNT=$(echo "$PROCESS_LIST" | wc -l)
PROCESS_AMOUNT=$((PROCESS_AMOUNT-1))

echo $PROCESS_AMOUNT > $FILE_NAME

echo "$PROCESS_LIST" | awk 'NR>1 {print $1 ":" $4}'
