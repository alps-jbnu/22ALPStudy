from sys import stdin

tree = list(map(lambda s: s.rstrip(), stdin.readlines()))
# tree = []
# for _ in range(29):
#     tree.append(input())
treeInfo = {}
total = len(tree)

for t in tree:
    if t in treeInfo:
        treeInfo[t] += 1
    else:
        treeInfo[t] = 1


for key in sorted(treeInfo.keys()):
    print('%s %.4f' % (key, treeInfo[key]/total * 100))

