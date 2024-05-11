#!/bin/bash

mkdir -p ~/test && echo "Success" > ~/report

date_time=$(date '+%d-%m-%Y_%H-%M-%S')
touch ~/test/"$date_time"
ping -c 1 www.net_nikogo.ru > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "$(date '+%d-%m-%Y_%H-%M-%S') Error" >> ~/report
fi
