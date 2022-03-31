from sys import stdin
from heapq import heappush, heappop

input = stdin.readline


def solution():
    minheap, maxheap = [], []
    solved = set()
    level_hash = {}

    N = int(input())
    for _ in range(N):
        P, L = map(int, input().rstrip().split())
        heappush(minheap, (L, P))
        heappush(maxheap, (-L, -P))
        level_hash[P] = L

    M = int(input())
    for _ in range(M):
        query = input().rstrip().split()
        commend = query[0]

        if commend == 'add':
            P, L = map(int, query[1:])
            heappush(minheap, (L, P))
            heappush(maxheap, (-L, -P))
            level_hash[P] = L

        elif commend == 'recommend':
            level = int(query[1])
            L, P = None, None
            if level == 1:
                L, P = maxheap[0]
                while (-P, -L) in solved:
                    heappop(maxheap)
                    L, P = maxheap[0]
                L = -L
                P = -P
            else:
                L, P = minheap[0]
                while (P, L) in solved:
                    heappop(minheap)
                    L, P = minheap[0]
            print(P)
        else:
            problem = int(query[1])
            solved.add((problem, level_hash[problem]))


solution()

