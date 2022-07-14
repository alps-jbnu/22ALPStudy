# 우선순위 큐 2개 쓰고, 지워진 것은 따로 기록해뒀다가
# 나중에 pq에서 꺼낼 때 지워진 거면 스킵하고 하나 더 꺼내는 풀이

from heapq import *
import sys
input = sys.stdin.readline

hard = []
easy = []
solved = set()
p_to_l = {}

N = int(input().rstrip())
for i in range(N):
    P, L = map(int, input().split())
    heappush(easy, (L, P))
    heappush(hard, (-L, -P))
    p_to_l[P] = L

M = int(input().rstrip())
for i in range(M):
    line = input().split()
    op = line[0]
    if op == 'recommend':
        x = int(line[1])
        if x == 1:
            while tuple(map(abs, hard[0])) in solved:
                trash = tuple(map(abs, heappop(hard)))
                solved.remove(trash)
            found = tuple(map(abs, hard[0]))
            print(found[1])
        else:  # x == -1
            while easy[0] in solved:
                trash = heappop(easy)
                solved.remove(trash)
            found = easy[0]
            print(found[1])
    elif op == 'add':
        P, L = map(int, line[1:])
        heappush(easy, (L, P))
        heappush(hard, (-L, -P))
        p_to_l[P] = L
    else:  # op == 'solved'
        P = int(line[1])
        lookfor = (p_to_l[P], P)
        solved.add(lookfor)
