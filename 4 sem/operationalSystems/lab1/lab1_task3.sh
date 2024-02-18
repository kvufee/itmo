#!/bin/bash

echo "choose parameter: "
echo "1 : nano"
echo "2 : vi"
echo "3 : browser"
echo "4 : exit"

read option

if [ "$option" = "1" ]; then
	nano
fi

if [ "$option" = "2" ]; then
        vi
fi
 
if [ "$option" = "3" ]; then
	firefox	
fi

if [ "$option" = "4" ]; then
	echo ""
fi
