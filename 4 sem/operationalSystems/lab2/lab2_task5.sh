#!/bin/bash

FILE_NAME="processInfo_v2.txt"

echo "" > $FILE_NAME

declare -A ppid_art_sum
declare -A ppid_count

for PID in $(ls /proc/ | grep -o '[0-9]*' | sort -n)
do
    if [ -d /proc/$PID ]
    then
        PAR_PID=$(grep -i "^PPid:" /proc/$PID/status | awk '{print $2}')

        SUM_EXEC_RUNTIME=$(grep -i "^se.sum_exec_runtime" /proc/$PID/sched | awk '{print $3}')
        NR_SWITCHES=$(grep -i "^nr_switches" /proc/$PID/sched | awk '{print $3}')

        if [ $NR_SWITCHES -ne 0 ]
        then
            ART=$(echo "$SUM_EXEC_RUNTIME / $NR_SWITCHES" | bc -l)
        else
            ART=0
        fi

        echo "ProcessID=$PID : Parent_ProcessID=$PAR_PID : Average_Running_Time=$ART" >> $FILE_NAME

        ppid_art_sum[$PAR_PID]=$(echo "${ppid_art_sum[$PAR_PID]}+$ART" | bc -l)
        ppid_count[$PAR_PID]=$((ppid_count[$PAR_PID]+1))
    fi
done

for PAR_PID in "${!ppid_art_sum[@]}"
do
    AVG_ART=$(echo "${ppid_art_sum[$PAR_PID]}/${ppid_count[$PAR_PID]}" | bc -l)
    echo "Average_Running_Children_of_ParentID=$PAR_PID is $AVG_ART" >> $FILE_NAME
done

sort -t "=" -k4 -n $FILE_NAME -o $FILE_NAME

