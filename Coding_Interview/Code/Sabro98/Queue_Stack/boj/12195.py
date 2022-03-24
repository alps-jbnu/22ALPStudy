from sys import stdin
from collections import deque


input = stdin.readline
T = int(input())
dp = {}
measures = []


def isAbleMake(num, able):
    s = str(num)
    for c in s:
        if not able[int(c)]:
            return False
    return True


def getMesure(num, able):
    ret = []
    for i in range(1, num + 1):
        if num % i == 0 and isAbleMake(i, able):
            ret.append(i)
    return ret


def solve(x):
    if x in dp:
        return dp[x]

    if x == 1:
        return 0

    dp[x] = 1e9

    for m in measures:
        if x < m:
            continue
        if x % m != 0:
            continue

        dp[x] = min(dp[x], solve(x//m) + len(str(m)) + 1)

    return dp[x]


def solution():
    global measures
    isAble = [True] * 10
    for i, t in enumerate(input().rstrip().split()):
        if t == '0':
            isAble[i] = False

    X = int(input())
    if X == 1:
        if isAble[1]:
            return 2
        else:
            return 1e9
    measures = getMesure(X, isAble)

    return solve(X)


for i in range(T):
    cnt = solution()
    result = cnt if cnt != 1e9 else "Impossible"
    print(f'Case #{i + 1}: {result}')
    dp = {}

