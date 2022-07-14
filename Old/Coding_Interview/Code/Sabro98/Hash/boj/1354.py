from sys import stdin

input = stdin.readline

N, P, Q, X, Y = map(int, input().rstrip().split())
dp = {}


def solution(i):
    if i <= 0:
        return 1

    if i in dp:
        return dp[i]

    dp[i] = solution(i // P - X) + solution(i // Q - Y)
    return dp[i]

print(solution(N))

