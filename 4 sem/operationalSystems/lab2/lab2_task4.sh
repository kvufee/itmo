#!/bin/bash

FILE_NAME="processInfo.txt"

echo "" > $FILE_NAME

for PID in $(ls /proc/ | grep -o '[0-9]*' | sort -n)
do
    if [ -d /proc/$PID ]
    then
        PAR_PID=$(grep -i "^Par_Pid:" /proc/$PID/status | awk '{print $2}')

        SUM_EXEC_RUNTIME=$(grep -i "^se.sum_exec_runtime" /proc/$PID/sched | awk '{print $3}')
        NR_SWITCHES=$(grep -i "^nr_switches" /proc/$PID/sched | awk '{print $3}')

        if [ $NR_SWITCHES -ne 0 ]
        then
            ART=$(echo "$SUM_EXEC_RUNTIME / $NR_SWITCHES" | bc -l)
        else
            ART=0
        fi

        echo "ProcessID=$PID : Parent_ProcessID=$PAR_PID : Average_Running_Time=$ART" >> $FILE_NAME
    fi
done

sort -t "=" -k4 -n $FILE_NAME -o $FILE_NAME
