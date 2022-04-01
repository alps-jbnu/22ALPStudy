import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

# 서로 다른 식
res = set()
bracket_pos = []

raw = input().rstrip()
st = []

for i in range(len(raw)):
    c = raw[i]
    if c == '(':
        st.append(i)
    elif c == ')':
        bracket_pos.append((st.pop(), i))

used = [True] * len(raw)


def backtrack(idx):
    if idx == len(bracket_pos):
        app_str = ""
        for i in range(len(raw)):
            if not used[i]:
                continue
            app_str += raw[i]
        res.add(app_str)
        return

    # used
    backtrack(idx+1)

    # not used
    used[bracket_pos[idx][0]] = False
    used[bracket_pos[idx][1]] = False
    backtrack(idx+1)
    used[bracket_pos[idx][0]] = True
    used[bracket_pos[idx][1]] = True


backtrack(0)
res = list(res)
res.sort()

for s in res:
    if raw != s:
        print(s)
