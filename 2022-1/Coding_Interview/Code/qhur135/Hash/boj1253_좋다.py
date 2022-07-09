save_dic = {} # 입력 저장 # key: 입력된 수들, value: 몇 개 입력 받았는지 개수
cnt_dic = {} # 사용한 숫자 체크하기 위한 딕셔너리

n = input()
good_number=0
input_lst= input().rstrip().split()

for num in input_lst: # 입력받은 숫자(key) 중복 해결하기 위해 카운트(value)
    if not save_dic.get(num):
        save_dic[num]=0 # 초기화
    save_dic[num]+=1 # 카운트

for num in save_dic.keys(): # 덧셈한 결과가 될 숫자
    cnt_dic = save_dic.copy()  # 복구
    plus_result = num # a+b=plus_result
    cnt_dic[num]-=1 # 사용
    for a in save_dic.keys(): # 더하는 숫자
        if cnt_dic[a]==0:
            continue # 사용할 수 없으면 다음 반복문으로
        cnt_dic[a]-=1 # 사용
        b = int(plus_result)-int(a) # 더하는 숫자

        if save_dic.get(str(b)): # b가 존재하고
            if cnt_dic[str(b)]>0: # 사용할 것이 남아있으면
                good_number+=(1*save_dic[num]) # 좋은 수 발견! 중복된 수 처리
                # 중복된 숫자가 있다면 해당 숫자도 좋은 수!
                break

print(good_number)
