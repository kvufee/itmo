#!/bin/bash

homeDir=$HOME
curDir=$PWD

if [ "$homeDir" == "$curDir" ]; then
	echo "vse ok"
	exit 0
else
	echo "error"
	exit 1
fi
