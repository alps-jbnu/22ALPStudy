import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

S = set()
N, M = map(int, input().split())
for i in range(N):
    S.add(input())
ans = 0
for i in range(M):
    test = input()
    if test in S:
        ans += 1

print(ans)
