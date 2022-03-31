from sys import stdin

input = stdin.readline

N = int(input())
A = list(map(int, input().rstrip().split()))

for i, a in enumerate(A):
    A[i] = (i, a)


def make(arr):
    st = []  # (index, value)
    ans = [-1e9] * N
    for i, a in arr:
        while st and st[-1][1] < a:
            ans[st.pop()[0]] = i
        st.append((i, a))

    return ans


def accumulate(arr, reverse=False):
    cnt = [0] * N
    if reverse:
        arr = arr[::-1]

    for i, r in enumerate(arr):
        if r == -1e9:
            continue
        index = N - i - 1 if reverse else i

        cnt[index] += cnt[r] + 1

    return cnt


def solution():
    right = make(A)
    left = make(A[::-1])

    right_cnt = accumulate(right, reverse=True)
    left_cnt = accumulate(left)

    for i in range(N):
        cnt = right_cnt[i] + left_cnt[i]
        if cnt == 0:
            print(0)
            continue
        print(cnt, end=' ')
        right_diff = abs(right[i] - i)
        left_diff = abs(left[i] - i)
        if left_diff <= right_diff:
            print(left[i] + 1)
        else:
            print(right[i] + 1)


solution()

