from collections import deque
import sys
input = sys.stdin.readline


N = int(input())
ops = list(map(int, input().split()))
# 아니 이걸 왜 했지? 어차피 pop()하면서 읽어서 뒤에서부터 읽는데?
# ops.reverse()

dq = deque()

for card in range(1, N+1):
    op = ops.pop()
    if op == 1:
        dq.append(card)
    elif op == 2:
        dq.insert(len(dq)-1, card)
    else:  # op == 3
        dq.appendleft(card)

dq.reverse()
for c in dq:
    print(c, end=' ')
