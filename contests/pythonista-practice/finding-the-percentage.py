def mean(l):
    return sum(l) / len(l)

marks = dict()

for x in range(int(input())):
    tokens = input().split()
    marks[tokens[0]] = mean([ float(i) for i in tokens[1:] ])

print("%.2f" % marks[input()])
