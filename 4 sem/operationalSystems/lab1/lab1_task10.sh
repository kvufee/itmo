#!/bin/bash

man bash | tr '[:upper:]' '[:lower:]' | tr -c '[:alpha:]' ' ' | tr -s ' ' '\n' | sort | uniq -c | awk 'length($2) >= 4 {print}' | sort -rn | head -3
