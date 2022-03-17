from sys import stdin
from collections import deque

input = stdin.readline

N, M = map(int, input().rstrip().split())
file_hash = {}
G = {}
fullName = {}

# init
for _ in range(N+M):
    P, F, C = input().rstrip().split()
    if C == '1':
        if P in G:
            G[P].append(F)
        else:
            G[P] = [F]
        if P not in file_hash:
            file_hash[P] = []
        if F not in file_hash:
            file_hash[F] = []
        if P not in G:
            G[P] = []
        if F not in G:
            G[F] = []
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

# move
K = int(input())
for _ in range(K):
    ssrc, ddst = input().rstrip().split()
    src, dst = map(lambda x: fullName[x], [ssrc, ddst])

    # move files
    file_hash[dst].extend(file_hash[src])
    file_hash[dst] = list(set(file_hash[dst]))

    # change graph, move folders
    dq = deque()
    for g in G[src]:
        dq.append((g, ''))
        G[dst].append(g)

    while dq:
        front = dq[0]
        name, path = front
        dq.popleft()
        fullName[ddst + f'{path}/{name}'] = name

        for g in G[name]:
            dq.append((g, path + f'/{name}'))

    # delete folder
    del fullName[ssrc]

    # delete folder
    del G[src]
    if src in file_hash:
        del file_hash[src]

    superFolder = ssrc.split('/')[-2]
    for i in range(len(G[superFolder])):
        if G[superFolder][i] == src:
            G[superFolder].pop(i)
            break


# query
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

