import sys
input = sys.stdin.readline

n = int(input().rstrip())
ans = 0
st = [0]
for _ in range(n):
    x, y = map(int, input().split())
    while len(st) != 0 and st[-1] > y:
        st.pop()
    # 기존 건물로 못 덮을 새로운 고층빌딩 등장시
    if len(st) == 0 or st[-1] != y:
        st.append(y)
        ans += 1

print(ans)
