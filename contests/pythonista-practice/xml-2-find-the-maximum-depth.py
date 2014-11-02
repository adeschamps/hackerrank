import xml.etree.ElementTree as etree

def height (node):
    return max([0] + [height(child) + 1 for child in node])

lines = int(input())

xml = ""
for l in range(lines):
    xml += input()

tree = etree.ElementTree(etree.fromstring(xml))

print (height(tree.getroot()))
