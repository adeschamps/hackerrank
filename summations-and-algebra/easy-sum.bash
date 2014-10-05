#!/bin/bash

read T

while read N m ; do
	sum=0
	for i in $(seq 1 $N) ; do
		sum=$(($sum + $i%$m))
	done
	echo $sum
done
