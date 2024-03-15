#!/bin/bash

for pid in $(ls /proc | grep -o '[[:digit:]]*')
do
    if [ -f /proc/$pid/io ]; then
        cat /proc/$pid/io | grep read_bytes | awk -v pid=$pid '{print pid " " $2}' >> before.txt
    fi
done

sleep 5

for pid in $(ls /proc | grep -o '[[:digit:]]*')
do
    if [ -f /proc/$pid/io ]; then
        cat /proc/$pid/io | grep read_bytes | awk -v pid=$pid '{print pid " " $2}' >> after.txt
    fi
done

join before.txt after.txt | awk '{print $1 " " $3-$2}' | sort -k2 -nr | head -n 3 | while read pid bytes
do
    cmd=$(ps -p $pid -o cmd --no-headers)
    echo "$pid:$cmd:$bytes"
done
