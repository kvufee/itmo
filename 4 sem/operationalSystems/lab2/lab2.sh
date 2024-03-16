#!/bin/bash


ps -eo pid,user,etimes,stat | awk '$4 ~ /S/ && $3 > 60 {print $1, $2}'

ps -eo pid,user,etimes,stat | awk '$4 > 60' | sort -nk3 | head -n3
