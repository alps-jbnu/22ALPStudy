from collections import defaultdict
n, p, q = input().split()
n = int(n)
p = int(p)
q = int(q)
seq_dic = defaultdict(int) # 딕셔너리 value값들 0으로 초기화
seq_dic[0]=1
# top down 방식 -> 필요한 것들만 구하므로 메모리 초과안남!!
def dp(n):
    if seq_dic[n]==0:# 저장이 안되어있으면
        seq_dic[n] = dp(int(n/p)) + dp(int(n/q)) # memo
    return seq_dic[n] # 재사용

# bottom up 방식 -> 메모리 초과 0~n까지 다 구하므로

result = dp(n)
print(result)
