from sys import stdin
from collections import deque

input = stdin.readline
A = input().rstrip()

st = []
ans = 0

for a in A:
    if a == '(':
        st.append(a)
    else:
        if st[-1] == '(':
            st.pop()
            st.append(1)
        else:
            cnt = 0
            while st[-1] != '(':
                cnt += st[-1]
                st.pop()
            st.pop()
            ans += cnt + 1
            st.append(cnt)
print(ans)
