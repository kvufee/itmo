#!/bin/bash

if [ ! -f /etc/passwd ]; then
	echo "/etc/passwd net"
	exit 1
fi

awk -F: '{ print $1, $3 }' /etc/passwd | sort -nk2
