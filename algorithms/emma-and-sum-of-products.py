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



sys.stdin.readline()
numbers = [int(x) for x in sys.stdin.readline().split(' ')]

tests = int(sys.stdin.readline())
for i in range(tests):
    k = int(sys.stdin.readline())
    print (calcSum(0, k))
