import sys


input = sys.stdin.readline
N = int(input())
A, B = [], []

for _ in range(N):
    A.append(input().rstrip())

for _ in range(N):
    B.append(input().rstrip())


def solution():
    aHash = {}
    for i, a in enumerate(A):
        aHash[a] = i

    ans = set()

    for b1 in B:
        for b2 in B:
            if b1 == b2:
                break
            if aHash[b1] < aHash[b2]:
                ans.add(b2)

    # print(ans)
    return len(ans)


print(solution())

