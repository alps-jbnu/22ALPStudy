from sys import stdin
from collections import deque

input = stdin.readline

N, M = map(int, input().rstrip().split())
file_hash = {}
G = {}
fullName = {}

for _ in range(N+M):
    P, F, C = input().rstrip().split()
    if C == '1':
        if P in G:
            G[P].append(F)
        else:
            G[P] = [F]
    else:
        if P in file_hash:
            file_hash[P].append(F)
        else:
            file_hash[P] = []
            file_hash[P].append(F)

fullName['main'] = 'main'
dq = deque([('main', '')])

while dq:
    name, before = dq[0]
    dq.popleft()
    fname = before + (f'/{name}' if name != 'main' else name)
    fullName[fname] = name

    if name not in G:
        continue

    for node in G[name]:
        dq.append((node, fname))

Q = int(input())
for _ in range(Q):
    fname = input().rstrip()
    name = fullName[fname]
    s = set()
    cnt = 0

    dq = deque([name])

    while dq:
        front = dq[0]
        dq.popleft()

        if front in file_hash:
            for file in file_hash[front]:
                s.add(file)
                cnt += 1
        if front in G:
            for node in G[front]:
                dq.append(node)
    print(len(s), cnt)

