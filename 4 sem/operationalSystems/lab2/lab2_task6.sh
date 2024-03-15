#!/bin/bash

PID=$(ps -eo pid,%mem --sort=-%mem | head -n 2 | tail -n 1 | awk '{print $1}')

ps -p $PID -o pid,%mem,cmd
top -b -n 1 | head -n 10 | grep $PID
