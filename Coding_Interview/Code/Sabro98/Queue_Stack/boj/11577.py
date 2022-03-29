from sys import stdin
from collections import deque

input = stdin.readline
N, K = map(int, input().rstrip().split())
B = list(map(int, input().rstrip().split()))


def solution():
    global B
    dq = deque()
    cnt = 0

    for i in range(N):
        b = B[i]

        if dq and dq[0] < i:
            dq.popleft()

        state = (-1) ** len(dq)

        if state == -1:
            b = 1 if b == 0 else 0
            B[i] = b

        # flip
        if i < N - K + 1:
            if b == 1:
                dq.append(i + K - 1)
                cnt += 1
                B[i] = 0

    if sum(B) != 0:
        cnt = -1
    return cnt


cnt = solution()
print(cnt if cnt != -1 else 'Insomnia')

