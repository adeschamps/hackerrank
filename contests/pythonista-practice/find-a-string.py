def countoverlap (string, substring):
    count = 0
    for i in range(len(string)):
        if string[i:].startswith(substring):
            count = count + 1
    return count

string = input()
substring = input()

print(countoverlap(string, substring))
