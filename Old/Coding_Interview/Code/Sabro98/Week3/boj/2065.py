from sys import stdin
from collections import deque


input = stdin.readline

M, t, N = map(int, input().rstrip().split())
l, r = [], []

for i in range(N):
    time, pos = input().split()
    time = int(time)
    if pos == 'left':
        l.append((time, i))
    else:
        r.append((time, i))

l.sort(key=lambda x: x[0])
r.sort(key=lambda x: x[0])


def solution():
    ans = [0 for _ in range(N)]
    lq = deque(l)
    rq = deque(r)
    boat = []
    currPos = 'left'
    movetime = 0

    for i in range(111111):
        if movetime > 0:
            movetime -= 1
            continue

        while boat:
            curr = boat[-1]
            boat.pop()
            ans[curr[1]] = i

        if currPos == 'left':
            if lq and lq[0][0] <= i:
                while lq and lq[0][0] <= i and len(boat) < M:
                    boat.append(lq[0])
                    lq.popleft()
                currPos = 'right'
                movetime = t - 1
                continue
            elif rq and rq[0][0] <= i:
                currPos = 'right'
                movetime = t - 1
                continue

        else:
            if rq and rq[0][0] <= i:
                while rq and rq[0][0] <= i and len(boat) < M:
                    boat.append(rq[0])
                    rq.popleft()
                currPos = 'left'
                movetime = t - 1
                continue
            elif lq and lq[0][0] <= i:
                currPos = 'left'
                movetime = t - 1
                continue

    return ans


for ans in solution():
    print(ans)

