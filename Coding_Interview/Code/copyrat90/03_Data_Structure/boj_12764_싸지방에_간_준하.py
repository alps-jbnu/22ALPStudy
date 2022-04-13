# 풀이: https://velog.io/@copyrat90/BOJ-12764

from heapq import *
import sys
input = sys.stdin.readline

N = int(input().rstrip())
A = [tuple(map(int, input().split())) for _ in range(N)]
A.sort()  # O(NlogN)

pc_cnt = []
pc_usage = []  # heapq, elem: (end_time, pc_idx)
available_pc = []  # heapq, elem: idx
for start, end in A:
    # 이번 start 에 이미 사용 종료된 사람들을 다 꺼냄
    while pc_usage and pc_usage[0][0] < start:
        avail = heappop(pc_usage)
        # 사용 가능한 PC 목록 heap에 사용 종료된 PC의 idx 넣기
        heappush(available_pc, avail[1])

    # 사용 종료된 PC 발견
    if available_pc:
        pc_idx = heappop(available_pc)
        pc_cnt[pc_idx] += 1  # 사용한 사람 수 1명 추가
        heappush(pc_usage, (end, pc_idx))
    # 그런 PC가 없는 경우 (새 PC 보급 필요)
    else:
        # 새로운 PC 보급
        pc_cnt.append(1)
        heappush(pc_usage, (end, len(pc_cnt)-1))

print(len(pc_cnt))
for i in pc_cnt:
    print(i, end=' ')
