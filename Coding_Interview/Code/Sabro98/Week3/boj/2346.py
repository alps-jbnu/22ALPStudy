from sys import stdin
from collections import deque

input = stdin.readline

N = int(input())
A = list(map(int, input().rstrip().split()))


def solution():
    ans = []
    dq = deque([i for i in range(N)])

    for _ in range(N):
        curr = dq[0]
        ans.append(curr + 1)
        dq.popleft()
        cnt = A[curr]
        if not dq:
            break

        if cnt > 0:
            for _ in range(cnt - 1):
                dq.append(dq.popleft())
        else:
            for _ in range(-cnt):
                dq.appendleft(dq.pop())

    return ans


print(' '.join(map(str, solution())))

