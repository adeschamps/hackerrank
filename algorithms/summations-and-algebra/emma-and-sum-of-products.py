# Initially written for memoization, I found that the recursion stack was overflowing
# So I added the loop which computes everything first
# The program would have been more efficient had I written it using traditional dynamic programming

import sys

cache = {}
numbers = []

def calcSum (index, k):
    if index == len(numbers):
        return 0
    if k == 0:
        return 0

    key = (index, k)
    if not key in cache:
        if k == 1:
            value = numbers[index] + calcSum(index+1, k)
        else:
            value = numbers[index] * calcSum(index+1, k-1) + calcSum(index+1, k)
        cache[key] = value % 100003
    return cache[key]


N = int(sys.stdin.readline())
numbers = [int(x) for x in sys.stdin.readline().split()]


# Compute everything first so as not to overflow the recursion stack
i = N
while i >= 0:
    for j in range(1,N+1):
        calcSum(i,j)
    i = i - 1



tests = int(sys.stdin.readline())
for i in range(tests):
    k = int(sys.stdin.readline())
    print (calcSum(0, k))
