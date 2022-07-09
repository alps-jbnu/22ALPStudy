start_dic={} # key 차 이름, value 들어온 순서
end_lst = [] # 나오는 순서대로 차 이름
compare_lst = [] # 나오는 순서대로 들어올 땐 몇번째로 들어왔는지
cnt=0 # 추월한 차

n = int(input())
for i in range(n):
    car_num = input()
    start_dic[car_num]=i # 들어오는 차 순서대로 들어온 순서와 함께 저장
    # key 차 이름, value 들어온 순서

for i in range(n):
    car_num = input() # 나오는 순서대로 리스트에 저장
    end_lst.append(car_num)

for num in end_lst: # 나오는 순서대로 들어올 땐 몇번째로 들어왔는 지 저장
    start_idx = start_dic[num]
    compare_lst.append(start_idx)

# 이 부분이 생각하는 데 오래걸림..
for i in range(len(compare_lst)): # 뒤에 더 빨리 들어온 차가 있나 확인
    for e in compare_lst[i+1:]:
        if compare_lst[i]>e:
            cnt+=1 # 있다면 추월한 것
            break

print(cnt)
