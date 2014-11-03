import re

valid_emails = set()

for email in [ input() for i in range(int(input())) ]:
    if re.match("^[a-zA-Z0-9-_]+@[a-zA-Z0-9]+\.[a-z]{1,3}$", email):
        valid_emails.add(email)

ve = list(valid_emails)
ve.sort()
print (ve)
