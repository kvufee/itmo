#!/bin/bash

home="$HOME"
parameter="$1"
log="$home/.trash.log"
trash_dir="$home/.trash"

if [ "$#" -ne 1 ]; then
    echo "error malo argumentov"
    exit 1
fi

if [ ! -f "$parameter" ]; then
    echo "takogo file net -> $parameter"
    exit 1
fi

if [ ! -d "$trash_dir" ]; then
    mkdir "$trash_dir"
fi

if [ ! -f "$log" ]; then
    echo "net $log"
    exit 1
fi

hardlink=$(date +%s%N)
ln "$parameter" "$trash_dir/$hardlink"
rm "$parameter"

echo "$(realpath "$parameter") $hardlink" >> "$log"
echo "'$parameter' udalen"
