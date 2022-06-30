import sys
input = sys.stdin.readline

N = int(input().rstrip())
players = {}
for _ in range(N):
    name = input().rstrip()
    if name in players:
        players[name] += 1
    else:
        players[name] = 1

for _ in range(N-1):
    name = input().rstrip()
    players[name] -= 1
    if players[name] == 0:
        del players[name]

assert len(players) == 1
for name in players:
    print(name)
