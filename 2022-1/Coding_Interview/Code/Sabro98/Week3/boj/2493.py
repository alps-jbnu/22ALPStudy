from sys import stdin

input = stdin.readline

N = int(input())
A = list(map(int, input().rstrip().split()))[::-1]


def solution():
    ans, st = [0] * N, []

    for i, a in enumerate(A):
        while st and st[-1][1] < a:
            top = st.pop()
            ans[top[0]] = N - i
        st.append((N - i - 1, a))

    while st:
        top = st.pop()
        ans[top[0]] = 0
    return list(map(str, ans))


print(' '.join(solution()))


