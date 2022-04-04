import sys
input = sys.stdin.readline
INF = 999999

N = int(input().rstrip())
A = list(map(int, input().split()))
st = []  # id

ans_cnt = [0] * N
ans_min_dist_id = [INF] * N

# i번 건물의 좌측 관찰
for i in range(N):
    # i번 건물에 가린 낮은 건물들은, 뒷 건물에서도 영원히 못본다.
    while len(st) != 0 and A[st[-1]] <= A[i]:
        st.pop()
    if len(st) != 0:
        # 스택에 남은 건물들이, i번 왼쪽에서 볼 수 있는 건물
        ans_cnt[i] = len(st)
        # 스택의 꼭대기 건물이 왼쪽에서 가장 가까이 있는 볼 수 있는 건물
        ans_min_dist_id[i] = st[-1]
    st.append(i)

st.clear()
# i번 건물의 우측 관찰
for i in range(N-1, -1, -1):
    while len(st) != 0 and A[st[-1]] <= A[i]:
        st.pop()
    if len(st) != 0:
        ans_cnt[i] += len(st)
        # 스택의 꼭대기 건물(우측 근접) vs 기존(좌측 근접) 중 새로운 게 가까우면
        if ans_min_dist_id[i] == INF or abs(st[-1]-i) < abs(i-ans_min_dist_id[i]):
            ans_min_dist_id[i] = st[-1]
    st.append(i)

for i in range(N):
    print(ans_cnt[i], end=' ')
    if ans_min_dist_id[i] != INF:
        print(ans_min_dist_id[i]+1, end='')
    print()
