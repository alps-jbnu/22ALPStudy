from sys import stdin
from heapq import heappush, heappop

input = stdin.readline
group_minheap, group_maxheap = [[] for _ in range(111)], [[] for _ in range(111)]
minheap, maxheap = [], []
solved = set()
problem_hash = {}
level_minheap, level_maxheap = [[] for _ in range(111)], [[] for _ in range(111)]


def add(P, L, G):
    heappush(group_minheap[G], (L, P))
    heappush(group_maxheap[G], (-L, -P))
    problem_hash[P] = (L, G)
    heappush(level_minheap[L], ((P, G)))
    heappush(level_maxheap[L], ((-P, G)))
    heappush(minheap, (L, P, G))
    heappush(maxheap, (-L, -P, G))
    if (P, L, G) in solved:
        solved.remove((P, L, G))

def solution():
    N = int(input())
    for _ in range(N):
        P, L, G = map(int, input().rstrip().split())
        add(P, L, G)

    M = int(input())
    for _ in range(M):
        query = input().rstrip().split()
        commend = query[0]

        if commend == 'add':
            P, L, G = map(int, query[1:])
            add(P, L, G)

        elif commend == 'recommend':
            G, x = map(int, query[1:])
            if x == 1:
                L, P = group_maxheap[G][0]
                while (-P, -L, G) in solved:
                    heappop(group_maxheap[G])
                    L, P = group_maxheap[G][0]

                P = -P
            else:
                L, P = group_minheap[G][0]

                while (P, L, G) in solved:
                    heappop(group_minheap[G])
                    L, P = group_minheap[G][0]

            print(P)

        elif commend == 'recommend2':
            x = int(query[1])
            if x == 1:
                L, P, G = maxheap[0]
                while (-P, -L, G) in solved:
                    heappop(maxheap)
                    L, P, G = maxheap[0]
                ans = -P
            else:
                L, P, G = minheap[0]
                while (P, L, G) in solved:
                    heappop(minheap)
                    L, P, G = minheap[0]
                ans = P
            print(ans)
        elif commend == 'recommend3':
            x, threshold = map(int, query[1:])
            ans = None
            if x == 1:
                for i, heap in enumerate(level_minheap):
                    if i < threshold:
                        continue
                    if not heap:
                        continue
                    P, G = heap[0]
                    flag = False
                    while (P, i, G) in solved:
                        heappop(heap)
                        if not heap:
                            flag = True
                            break
                        P, G = heap[0]
                    if flag:
                        continue
                    ans = P
                    break
            else:
                for i, heap in enumerate(level_maxheap[::-1]):
                    if len(level_maxheap) - i - 1 >= threshold:
                        continue
                    if not heap:
                        continue
                    P, G = heap[0]
                    flag = False
                    while (-P, len(level_maxheap) - i - 1, G) in solved:
                        heappop(heap)
                        if not heap:
                            flag = True
                            break
                        P, G = heap[0]
                    if flag:
                        continue
                    ans = -P
                    break
            print(ans if ans else -1)
        else:
            problem = int(query[1])
            info = problem_hash[problem]
            solved.add((problem, info[0], info[1]))


solution()

