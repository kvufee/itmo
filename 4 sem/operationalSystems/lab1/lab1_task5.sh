#!/bin/bash

if [ ! -f /var/log/anaconda/syslog ]; then
	echo "file ne sozdan"
	exit 1
fi

awk '$2 == "INFO"' /var/log/anaconda/syslog > info_task5.log 
