import re

for num in [ input() for i in range(int(input())) ]:
    if re.match("^[789][0-9]{9}$", num):
        print("YES")
    else:
        print("NO")
