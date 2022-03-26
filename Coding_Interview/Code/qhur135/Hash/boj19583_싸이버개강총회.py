import sys
attend_dic={}
cheat = sys.stdin.read().rstrip().split("\n")
# f = open("input.txt")
# cheat = f.readlines()
cnt=0
s,e,q = cheat[0].rstrip().split()
s = int(s.replace(":","")) # 12:00 -> 1200
e = int(e.replace(":",""))
q = int(q.replace(":",""))

for line in cheat[1:]:
    time, name = line.rstrip().split()
    time = int(time.replace(":",""))
    if time <= s: # 입장 출석체크
        attend_dic[name]=1
    elif e <= time <= q: # 퇴장 출석체크
        if attend_dic.get(name) and attend_dic[name]==1: # 입장 때 채팅했다면
            attend_dic[name]=0 # 중복처리
            cnt+=1 # 카운트

print(cnt)
