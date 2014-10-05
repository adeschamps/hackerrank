from sys import *
from math import *

K = int(stdin.readline().split()[1])
numbers = [ int(x) for x in stdin.readline().split() ]
numbers.sort()

pairs = 0
back = 0
front = 0

while front < len(numbers):
    diff = numbers[front] - numbers[back]
    if diff == K:
        pairs += 1
        front += 1
    elif diff > K:
        back += 1
    else:
        front += 1

print (pairs)
