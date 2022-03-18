from sys import stdin
input = stdin.readline


loyal = {}
N, M = map(int, input().rstrip().split())
pioneer = input().rstrip()
loyal[pioneer] = 1

family = [input().rstrip().split() for _ in range(N)]

flag = False
while not flag:
    flag = True
    for i in range(N):
        child = family[i][0]
        for j in range(i):
            p1, p2 = family[j][1:]
            if child == p1 or child == p2:
                f = family[j]
                family.pop(j)
                family.insert(i, f)
                flag = False
                break
        if not flag:
            break


for f in family:
    offspring, p1, p2 = f
    blood = 0
    for p in (p1, p2):
        if p in loyal:
            blood += loyal[p]/2
    loyal[offspring] = blood

targets = [input().rstrip() for _ in range(M)]

max = -1
ans = ''

for t in targets:
    if t not in loyal:
        continue
    if max < loyal[t]:
        max = loyal[t]
        ans = t

# for f in family:
#     print(f)
# print(loyal)
print(ans)

