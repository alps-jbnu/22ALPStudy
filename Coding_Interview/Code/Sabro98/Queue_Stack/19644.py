from sys import stdin
from collections import deque


# input = stdin.readline


def solution():
    L = int(input())
    # ML, MK = map(int, input().rstrip().split())
    ML, MK = map(int, input().split())
    C = int(input())
    # Z = [int(input().rstrip()) for _ in range(L)]
    Z = [int(input()) for _ in range(L)]

    dq = deque()

    for i in range(L):
        hp = Z[i]

        # 범위 벗어난 데미지 빼기
        if dq and dq[0] < i:
            dq.popleft()

        # 좀비가 없으면 그냥 쏘기
        if hp == 0:
            dq.append(i + ML - 1)
            continue

        # 좀비가 있을 때

        # 잔여 체력 계산
        hp -= len(dq) * MK

        if hp > 0:
            # 쏘면 죽음
            if hp - MK <= 0:
                dq.append(i + ML - 1)

            # 쏴도 안죽음
            elif C > 0:
                C -= 1
            else:
                return True
        else:
            dq.append(i + ML - 1)

    return False


daed = solution()
print("NO" if daed else "YES")


