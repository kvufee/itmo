#!/bin/bash

home=$HOME
parameter="$1"
logfile="$home/.trash.log"
trash_dir="$home/.trash"

if [ "$#" -ne 1 ]; then
    echo "error malo argumentov"
    exit 1
fi

if [ ! -f "$logfile" ]; then
    echo "net $logfile"
    exit 1
fi

if [ ! -d "$trash_dir" ]; then
    mkdir "$trash_dir"
fi

entries=$(grep -F "$parameter" "$logfile")

if [ -z "$entries" ]; then
    echo "$parameter net v trash log"
    exit 1
fi

echo "$entries"
read -p "vosstanovit? (Y/n) " answer

if [ "$answer" != "y" ]; then
    echo "ne bylo"
    exit 0
fi

while read -r entry; do
    full_path=$(echo "$entry" | cut -d' ' -f1)
    hardlink=$(echo "$entry" | cut -d' ' -f1-2)
    echo $hardlink
    dir_name=$(dirname "$full_path")
    base_name=$(basename "$full_path")

    if [ ! -d "$dir_name" ]; then
        dir_name="$home"
        echo "papki net idi domoy"
    fi

    if ln $home/.trash/"$hardlink" "$dir_name/$base_name"; then
        rm $home/.trash/"$hardlink"
    else
        echo "imya plohoe"
        read -p "novoe imya: " new_name
        ln $home/.trash/"$hardlink" "$dir_name/$new_name"
        rm $home/.trash/"$hardlink"
    fi
done <<< "$entries"

echo "vse norm"
