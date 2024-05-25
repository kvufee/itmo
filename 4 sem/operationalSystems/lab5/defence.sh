#!/bin/bash

MEMORY_LOG="memory_usage.log"

showMemUsage() {
  cat "$MEMORY_LOG"
}

logMemUsage() {
  while read -r pid; do
    process_name=$(ps -p $pid -o comm=)
    memory_usage=$(pmap $pid | tail -n 1 | awk '/[0-9]K/{print $2}')
    
    if grep -q "^$pid " "$MEMORY_LOG"; then
      sed -i "/^$pid / s/$/ $memory_usage/" "$MEMORY_LOG"
    else
      echo "$pid $process_name: $memory_usage" >> "$MEMORY_LOG"
    fi
  done < <(ps -eo pid)
}

if [[ $1 == "show" ]]; then
  showMemUsage
else
  logMemUsage
fi

