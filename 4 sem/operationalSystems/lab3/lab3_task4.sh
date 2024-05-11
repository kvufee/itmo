#!/bin/bash

# Запуск трех фоновых процессов
for i in {1..3}
do
    (while true; do echo "scale=2; 9000000000 - 0.01" | bc > /dev/null; done) &
    if [ $i -eq 1 ]; then
        first_pid=$!
    elif [ $i -eq 3 ]; then
        third_pid=$!
    fi
done

cat << EOF > limit_cpu_usage.sh
#!/bin/bash
while true; do
    cpu_usage=\$(top -b -n 1 -p $first_pid | tail -1 | awk '{print \$9}')
    if (( \$(echo "\$cpu_usage > 10.0" | bc -l) )); then
        kill -STOP $first_pid
        sleep 5
        kill -CONT $first_pid
    fi
    sleep 5
done
EOF

bash limit_cpu_usage.sh &

kill -SIGTERM $third_pid
