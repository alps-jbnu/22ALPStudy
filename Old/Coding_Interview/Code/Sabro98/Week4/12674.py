from sys import stdin
from heapq import heappush, heappop
from collections import deque

input = stdin.readline

N = int(input())
A = [list(map(int, input().rstrip().split())) for _ in range(N)]
A.sort()


def solution():
    # (end time, seat number)
    using = []
    # seat number
    remain = []

    ans = {}
    dq = deque(A)

    # 자리 1개 생성
    heappush(remain, 1)
    cnt = 1
    ans[cnt] = 0

    for t in range(1000001):
        if not dq:
            break

        # 다 사용한 자리 빼주기
        while using and using[0][0] == t:
            _, s = heappop(using)
            heappush(remain, s)

        curr = dq[0]

        if curr[0] == t:
            dq.popleft()

            # 여유석 없으면 만들기
            if not remain:
                cnt += 1
                ans[cnt] = 0
                heappush(remain, cnt)

            r = heappop(remain)
            ans[r] += 1
            heappush(using, (curr[1], r))

    return ans


ans = solution()
print(len(ans.keys()))
for key in sorted(ans.keys()):
    print(ans[key], end=' ')

'''
5
10 100
20 50
30 120
60 110
80 90

1
10 ~ 100
2 1 
60 ~ 110
3
30 ~ 120
4
80 ~ 90
'''
