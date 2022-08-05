import sys
input = sys.stdin.readline

# { "125", "215", ... }
paths = set()
N: str = input().rstrip()


def backtrack(left: int, right: int, acc_order: str):
    # N 생성 완료시 set에 넣어 중복 제거
    if left == 0 and right == len(N)-1:
        paths.add(acc_order)
        return

    # [실수] 숫자를 적는 과정에서 나온 수가 순서대로 모두 같다면 같은 방법이다.
    # -> 8 80 808 이렇게 "만들어지는 중간 결과"를 전부 보라는 의미 (자리수만 보는 게 아님!)
    # -> 8 08 808 하고 위에거하고는 다르다.
    if left > 0:
        backtrack(left-1, right, acc_order+(acc_order+N[left-1]))
    if right < len(N)-1:
        backtrack(left, right+1, acc_order+(N[right+1]+acc_order))


# 시작 idx 지정
for start_idx in range(len(N)):
    # 좌우 백트래킹
    backtrack(start_idx, start_idx, N[start_idx])

print(len(paths))
