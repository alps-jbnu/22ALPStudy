from itertools import accumulate
from collections import defaultdict
import sys
input = sys.stdin.readline

days_of_month = tuple(accumulate(
    (0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)))


def minutes_since_2021(day: str, time: str) -> int:
    month = int(day[5:7])
    day = int(day[8:10])
    hour = int(time[0:2])
    minute = int(time[3:5])

    day += days_of_month[month] - 1
    minute += day * 24 * 60 + hour * 60
    return minute


if __name__ == '__main__':
    raw = input().split()
    N = int(raw[0])
    DDD = int(raw[1][0:3])
    hh = int(raw[1][4:6])
    mm = int(raw[1][7:9])
    L = (DDD*24*60) + (hh * 60) + mm
    F = int(raw[2])

    inputs = [input().split() for _ in range(N)]
    # 입력 시간순 정렬
    inputs.sort()

    history = defaultdict(dict)
    fees = defaultdict(int)  # 이름->벌금
    for day, time, P, M in inputs:
        minutes = minutes_since_2021(day, time)
        # 반납
        if P in history[M]:
            used_min = minutes - history[M][P]
            if used_min > L:
                fee = (used_min-L)*F
                fees[M] += fee
            del history[M][P]
            pass
        # 대여
        else:
            history[M][P] = minutes

    fees = list(fees.items())
    if fees:
        fees.sort()
        for name, fee in fees:
            print(name, fee)
    else:
        print(-1)
