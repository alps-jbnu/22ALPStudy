from sys import stdin

input = stdin.readline

info = {}

Q = int(input().rstrip())


def solution():
    global info

    ans = 0
    for _ in range(Q):
        inp = input().rstrip().split()
        query, name, value = inp[0], inp[1], inp[2:]

        if query == '1':
            value = list(map(int, value[1:]))
            if name in info:
                info[name].extend(value)
            else:
                info[name] = value
        else:
            if name in info:
                info[name].sort()
                for _ in range(int(value[0])):
                    if not info[name]:
                        break
                    val = info[name].pop()
                    ans += val
    return ans


print(solution())

