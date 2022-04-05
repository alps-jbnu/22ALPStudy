from sys import stdin

input = stdin.readline

# 괄호 -> 최대 10개, 2^10

A = input().rstrip()
pos = []
ans = []


def recur(x, curr):
    global ans
    if x == len(pos):
        ans.append(''.join([a for a in curr if a != 'x']))
        return

    eliminate = curr.copy()
    eliminate[pos[x][0]] = 'x'
    eliminate[pos[x][1]] = 'x'

    recur(x+1, curr)
    recur(x+1, eliminate)


def solution():
    global pos
    st = []
    for i, a in enumerate(A):
        if a == '(':
            st.append(i)
        elif a == ')':
            pos.append((st.pop(), i))
    recur(0, list(A))
    answer = list(set(ans))

    for a in sorted(answer):
        if a == A:
            continue
        print(a)


solution()

