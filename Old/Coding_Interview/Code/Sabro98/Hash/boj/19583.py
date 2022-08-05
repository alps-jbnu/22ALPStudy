import sys


# input = sys.stdin.readline
S, E, Q = input().rstrip().split()


def isBefore(time, standard):
    th, tm = time.split(':')
    sh, sm = standard.split(':')

    if th == sh:
        return tm <= sm

    return th < sh


def isBetween(time, left, right):
    th, tm = time.split(':')
    lh, lm = left.split(':')
    rh, rm = right.split(':')

    if lh == th == rh:
        return lm <= tm <= rm
    elif lh == th < rh:
        return lm <= tm
    elif lh < th == rh:
        return tm <= rm

    return lh < th < rh


def solution():
    before, after = set(), set()

    for chat in chats:
        time, name = chat.split()
        if isBefore(time, S):
            before.add(name)
        if isBetween(time, E, Q):
            after.add(name)

    return len(before & after)


chats = sys.stdin.readlines()
print(solution())

