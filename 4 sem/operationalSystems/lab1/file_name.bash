#!/bin/bash

file_name=$1
log_source=$2
log_level=$3

if [ ! -f "$file_name" ]; then
    echo "grustno"
    exit 1
fi

if [ -f "${file_name}.sh" ]; then
    old_version=$(grep -oP '#Version \K.*' "${file_name}.sh")
    new_version=$(grep -oP '#Version \K.*' "$file_name")

    if [[ "$new_version" > "$old_version" ]]; then
        echo "norm"
    else
        echo "grustno."
        exit 1
    fi
fi

cp "$file_name" "${file_name}.sh"
sed -i '/#TEMPLATE/d' "${file_name}.sh"

if [ "$log_source" = "console" ]; then
    echo "norm"
else
    echo "norm balls" > install.log
fi
