#!/bin/bash

# This is correct, but terminates due to timeout

read T

for t in $(seq 1 $T) ; do
	read N m
	sum=0
	for i in $(seq 1 $N) ; do
		sum=$(($sum + $i%$m))
	done
	echo $sum
done
