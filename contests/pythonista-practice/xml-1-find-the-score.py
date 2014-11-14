import xml.etree.ElementTree as etree

def count_attrib (node):
    count = len(node.attrib)
    for child in node:
        count += count_attrib(child)
    return count

lines = int(input())

xml = ""
for l in range(lines):
    xml += input()

tree = etree.ElementTree(etree.fromstring(xml))

print (count_attrib(tree.getroot()))
