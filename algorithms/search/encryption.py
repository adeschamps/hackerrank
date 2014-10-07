from sys import *
from math import *

string = stdin.readline()

cols = ceil (sqrt(len(string)))
rows = ceil (len(string) / cols)

# print ("rows: " + str(rows))
# print ("cols: " + str(cols))

encoded = ""
for col in range(cols):
    for row in range(rows):
        i = row*cols + col
        if i < len(string):
            encoded += string[i]
    encoded += ' '

print (encoded)
