read N
for i in $(seq 1 $N) ; do
	read line
	if   echo $line | grep -E '^hackerrank.+' > /dev/null ; then echo  1
	elif echo $line | grep -E '.+hackerrank$' > /dev/null ; then echo  2
	elif echo $line | grep -E '^hackerrank$'  > /dev/null ; then echo  0
	else                                                         echo -1
	fi
done
