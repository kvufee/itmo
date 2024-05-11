#!/bin/bash

mkfifo pipe

mode="add"
result=1

while true; do
    if read line < pipe; then
        case "$line" in
            "+")
                mode="add"
                ;;
            "*")
                mode="umnoj"
                ;;
            "QUIT")
                echo "HANDLER STOP"
                break
                ;;
            *)
                if [[ $line =~ ^[0-9]+$ ]]; then
                    if [ "$mode" == "add" ]; then
                        result=$(($result + $line))
                    else
                        result=$(($result * $line))
                    fi
                    echo "Result: $result"
                else
                    echo "ERROR"
                    break
                fi
                ;;
        esac
    fi
done
