package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)
	var x, result int
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &x)
		result = result ^ x
	}
	fmt.Println(result)
}
