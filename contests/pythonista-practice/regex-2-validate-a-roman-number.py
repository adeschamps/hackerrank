import re

string = input();

rn = "M{,3}(C[DM]|D?C{,3})(X[LC]|L?X{,3})(I[VX]|V?I{,3})"

if re.match("^" + rn + "$", string):
    print("True")
else:
    print("False")
