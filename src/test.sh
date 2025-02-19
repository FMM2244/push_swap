ARG=`python3 rangen.py 5`;
./push_swap $ARG | wc -l >> log

echo $ARG >> log

tail -2 log
