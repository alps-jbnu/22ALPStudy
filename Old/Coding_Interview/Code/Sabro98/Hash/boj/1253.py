import sys


input = sys.stdin.readline
N = int(input())
A = list(map(int, input().rstrip().split()))


def solution():
    s = {}
    for a in A:
        if a in s:
            s[a] += 1
        else:
            s[a] = 1

    cnt = 0
    for target in A:
        s[target] -= 1
        for a in A:
            if s[a] <= 0:
                continue
            s[a] -= 1
            if target - a in s and s[target - a] > 0:
                cnt += 1
                s[a] += 1
                break

            s[a] += 1
        s[target] += 1

    return cnt


print(solution())

