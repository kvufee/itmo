#!/bin/bash

if [ ! -d /etc ]; then
    echo "/etc net na kompe"
    exit 1
fi

grep -rIhEo "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}" /etc | tr '\n' ',' > emails.lst
