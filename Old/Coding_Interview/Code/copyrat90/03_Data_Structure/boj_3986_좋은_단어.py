import sys
input = sys.stdin.readline

N = int(input())
ans = 0
for i in range(N):
    word = input().rstrip()
    st = []
    for ch in word:
        if len(st) == 0 or st[len(st)-1] != ch:
            st.append(ch)
        else:
            st.pop()
    if len(st) == 0:
        ans += 1

print(ans)
