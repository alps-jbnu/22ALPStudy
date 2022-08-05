import sys

input = sys.stdin.readline
dp = {}
N, P, Q = map(int, input().rstrip().split())


def solution(N):
    global dp

    if N == 0:
        return 1

    if N in dp:
        return dp[N]

    dp[N] = solution(N//P) + solution(N//Q)
    return dp[N]

print(solution(N))

