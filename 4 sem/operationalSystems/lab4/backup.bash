#!/bin/bash

home=$HOME
source="$home/source"
report="$home/backup-report"
current_date=$(date +%Y-%m-%d)
backup=$(find "$home" -maxdepth 1 -type d -name "Backup-*" -mtime -7 | sort | tail -n 1)

if [ -z "$backup" ]; then
    backup="$home/Backup-$current_date"
    mkdir "$backup"
    echo "catalog backupa sozdan $backup" >> "$report"
fi

for source in "$source"/*; do
    file=$(basename "$source")
    backup_file="$backup/$file"
    
    if [ ! -f "$backup" ]; then
        cp "$source" "$backup_file"
        echo "noviy file $file" >> "$report"
    else
        source_size=$(stat -c%s "$source")
        backup_size=$(stat -c%s "$backup_file")

        if [ "$source_size" -ne "$backup_size" ]; then
            mv "$backup_file" "$backup.$current_date"
            cp "$source" "$backup_file"
            echo "noviy file $file (proshlyi -> $file.$current_date)" >> "$report"
        fi
    fi
done

echo "sdelano"

