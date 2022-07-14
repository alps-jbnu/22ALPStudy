from sys import stdin

input = stdin.readline


dx, dy = [-1, 1, 0, 0, -1, -1, 1, 1], [0, 0, -1, 1, -1, 1, -1, 1]
dp = {}
ansdp = {}
N, M, K = map(int, input().rstrip().split())
A = [[c for c in input().rstrip()] for _ in range(N)]
targets = [input().rstrip() for _ in range(K)]


def solution(x, y, curr, target):
    # 현재 위치 x, y, 현재 문자열 curr, 목표 문자열 target
    curr += A[x][y]
    if curr == target:
        return 1
    if len(curr) > len(target):
        return 0

    for i in range(len(curr)):
        if curr[i] != target[i]:
            return 0

    if (x, y) in dp and curr in dp[(x, y)]:
        return dp[(x, y)][curr]

    count = 0
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]

        if nx == N:
            nx = 0
        elif nx == -1:
            nx = N - 1

        if ny == M:
            ny = 0
        elif ny == -1:
            ny = M - 1

        count += solution(nx, ny, curr, target)

    dp[(x, y)] = {}
    dp[(x, y)][curr] = count
    return count


for target in targets:
    ans = 0
    if target in ansdp:
        print(ansdp[target])
        continue
    for i in range(N):
        for j in range(M):
            ans += solution(i, j, '', target)
    print(ans)
    ansdp[target] = ans
    dp = {}

