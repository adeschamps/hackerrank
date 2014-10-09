read N
for i in $(seq 1 $N) ; do
	read line
	if echo $line | grep -E '[A-Z]{5}[0-9]{4}[A-Z]' > /dev/null ; then
		echo "YES"
	else
		echo "NO"
	fi
done
