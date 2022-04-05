from sys import stdin

input = stdin.readline

N = int(input())
A = sorted(list(map(lambda x: (int(x[0]), int(x[1])), [input().rstrip().split() for _ in range(N)])))


def solution():
    ans = 0
    st = []
    for x, y in A:
        if not st:
            if y == 0:
                continue
            st.append(y)
        elif st[-1] < y:
            st.append(y)
        else:
            while st and st[-1] > y:
                st.pop()
                ans += 1
            if not st and y != 0:
                st.append(y)
            elif st and st[-1] != y and y != 0:
                st.append(y)
    ans += len(st)
    return ans


print(solution())

