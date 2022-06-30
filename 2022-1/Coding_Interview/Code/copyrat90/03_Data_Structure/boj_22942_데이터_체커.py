import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# k번째 원의 왼쪽끝 좌표를 'k{'로, 오른끝을 '}k'로 보면
# 괄호 검사하는 문제와 비슷 (단, 같은 좌표도 틀림 처리)

# 원소: (좌표, 원_id)
# 원_id: 여는괄호=음수, 닫는괄호=양수
bracket = []

N = int(input())
for i in range(N):
    x, r = map(int, input().split())
    bracket.append((x-r, -(i+1)))
    bracket.append((x+r, i+1))

# O(NlogN)
bracket.sort()

# 같은 좌표 존재하면 1개짜리 교점 존재, 틀림 처리
for i in range(N-1):
    if (bracket[i][0] == bracket[i+1][0]):
        print("NO")
        exit(0)

# 괄호 검사
st = []
for _, id in bracket:
    # 여는 괄호
    if id < 0:
        st.append(-id)
    # 닫는 괄호
    else:
        if len(st) == 0 or st[len(st)-1] != id:
            print("NO")
            exit(0)
        st.pop()

if len(st) == 0:
    print("YES")
else:
    print("NO")
