from collections import deque


def solution(progresses, speeds):
    answer = []
    q = deque(progresses)
    sq = deque(speeds)

    day = 1
    while q:
        if q[0] + day * sq[0] >= 100:
            cnt = 0
            while q and q[0] + day * sq[0] >= 100:
                q.popleft()
                sq.popleft()
                cnt += 1
            answer.append(cnt)
        day += 1

    return answer

