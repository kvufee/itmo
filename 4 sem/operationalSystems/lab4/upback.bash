#!/bin/bash

home=$HOME
restore="$home/restore"
backup=$(find "$home" -maxdepth 1 -type d -name "Backup-*" | sort | tail -n 1)

if [ -z "$backup" ]; then
    echo "backupa net"
    exit 1
fi

if [ ! -d "$restore" ]; then
    mkdir "$restore"
fi

for backup_file in "$backup"/*; do
    file=$(basename "$backup_file")
    
    if [[ "$file" != *"."* ]]; then
        cp "$backup_file" "$restore/$file"
    fi
done

echo "vosstanovleno"
