#!/bin/bash

handler_pid=$1

while true; do
    read line
    case "$line" in
        "+")
            kill -USR1 $handler_pid
            ;;
        "*")
            kill -USR2 $handler_pid
            ;;
        "TERM")
            kill -SIGTERM $handler_pid
            echo "GENERATOR STOP"
            exit 0
            ;;
        *)
            echo "IGNORE $line"
            ;;
    esac
done
