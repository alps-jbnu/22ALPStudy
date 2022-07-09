from sys import stdin

input = stdin.readline

R, C = map(int, input().split())
targets = ['' for _ in range(C)]


def solution():
    count = 0
    global targets

    while targets[0] != '':
        s = set()
        subtargets = list(map(lambda x: x[1:], targets))

        for target in subtargets:
            if target in s:
                return count
            s.add(target)

        count += 1

        targets = subtargets
    return count


for _ in range(R):
    strings = input().rstrip()
    for j, c in enumerate(strings):
        targets[j] += c

print(solution())
