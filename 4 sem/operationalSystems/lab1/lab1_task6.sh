#!/bin/bash

if [ ! -f /var/log/anaconda/X.log ]; then
    echo "file ne sozdan"
    exit 1
fi

warnings=$(mktemp)
info=$(mktemp)

grep 'Warning' /var/log/anaconda/X.log | sed 's/warning/Warning:/g' > $warnings
grep 'Information' /var/log/anaconda/X.log | sed 's/info/Information:/g' > $info

cat $warnings $info > full_task6.log
rm $warnings $info
cat full.log
