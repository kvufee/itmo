#!/bin/bash

if [ ! -d /var/log ]; then
	echo "Директория /var/log не найдена"
	exit 1
fi

lines=0
for file in /var/log/*.log; do
	if [ -f "$file" ]; then
		lines=$(wc -l < "$file")
        	total_lines=$((total_lines + lines))
    	fi
done

echo "$lines"
