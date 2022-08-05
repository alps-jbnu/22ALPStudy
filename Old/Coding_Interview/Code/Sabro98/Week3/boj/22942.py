from sys import stdin
from collections import deque

input = stdin.readline

N = int(input())
A = []
for _ in range(N):
    x, r = map(int, input().split())
    l, u = x - r, x + r
    A.append((l, u))


def solution():
    A.sort()
    st = []
    visited = [False] * 2222222

    for a in A:
        if visited[a[0]] or visited[a[1]]:
            return "NO"
        visited[a[0]] = True
        visited[a[1]] = True

        while st and st[-1][1] < a[0]:
            st.pop()

        if st and a[0] < st[-1][1] < a[1]:
            return "NO"

        st.append(a)
    return "YES"


print(solution())

