from sys import stdin

input = stdin.readline

S = input().rstrip()
N = len(S)
dp = {}


def solution(curr):
    if curr == S:
        return 1

    if curr in dp:
        return dp[curr]

    cnt = 0
    visited = set()
    for s in range(10):
        s = str(s)
        if s + curr in S:
            cnt += solution(s + curr)
            visited.add(s + curr)
        if curr + s in S and curr + s not in visited:
            cnt += solution(curr + s)
            visited.add(curr + s)

    dp[curr] = cnt

    return dp[curr]


ans = 0
for s in range(10):
    s = str(s)
    if s not in S:
        continue
    ans += solution(s)
print(ans)
'''
001

0 -> 00 -> 001

0 -> 01 -> 001

1 -> 01 -> 001
'''
