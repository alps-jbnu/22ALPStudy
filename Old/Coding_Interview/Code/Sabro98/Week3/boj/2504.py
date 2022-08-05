from sys import stdin
from collections import deque

input = stdin.readline
A = input().rstrip()

st = []


def check(st, a):
    if st and st[-1] == a:
        st.pop()
    else:
        print(0)
        exit(0)


def update(st, score):
    cnt = 0
    while st[-1] != '(' and st[-1] != '[':
        cnt += st[-1]
        st.pop()
    st.pop()

    if cnt == 0:
        cnt = 1
    cnt *= score

    st.append(cnt)


for a in A:
    if a == '(' or a == '[':
        st.append(a)
    else:
        check(st, '(' if a == ')' else '[')

if st:
    print(0)
    exit(0)

st = []
for a in A:
    if a == '(' or a == '[':
        st.append(a)
        st.append(0)
    else:
        update(st, 2 if a == ')' else 3)

print(sum(st))

