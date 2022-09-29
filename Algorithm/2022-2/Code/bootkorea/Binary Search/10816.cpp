from sys import stdin
_ = stdin.readline()
N = sorted(map(int, stdin.readline().split()))
_ = stdin.readline()
M = map(int, stdin.readline().split())

def binary(num, N, start, end) :
    if start > end:
return 0
a = (start + end) // 2
if num == N[a] :
    return N[start:end + 1].count(num)
    elif num < N[a] :
    return binary(num, N, start, a - 1)
else:
return binary(num, N, a + 1, end)

a_dic = {}
for n in N :
start = 0
end = len(N) - 1
if n not in a_dic :
a_dic[n] = binary(n, N, start, end)

print(' '.join(str(a_dic[x]) if x in a_dic else '0' for x in M))