# Works, but times out on a few test cases

sum=0
index=1
mod_value=1000000007

while read -n 1 digit ; do
	sum=$((($sum * 11 + $digit * $index) % $mod_value))
	index=$((($index * 2) % $mod_value))
done

echo $sum
