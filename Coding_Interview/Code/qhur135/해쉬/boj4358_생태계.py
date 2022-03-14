import sys
trees_dic = {}
total = 0
# f = open("input.txt","r") # test코드
# trees_lst = f.read().split("\n") # test코드
trees_lst = sys.stdin.read().rstrip().split("\n")
# read() 입력 전체 읽어서 문자열로 저장, rstrip으로 맨 뒤 개행 없애기, split('\n') 개행 기준으로 나눠서 리스트로 저장
# read().rstrip() 같이 쓰기!!

for tree in trees_lst:
    if not trees_dic.get(tree): # 초기화
        trees_dic[tree]=0
    total += 1  # 전체 카운트
    trees_dic[tree] += 1 # 종 별로 나무 카운트

trees_dic = sorted(trees_dic.items()) # 종 이름으로 정렬
for tree in trees_dic:
    name = tree[0]
    cnt = tree[1]
    # print(tree[0].strip()+" "+str(round(tree[1]/total*100,4)))
    # round 사용하면 틀림 -> round(0.5, 4)= 0.5 , round(-0.5, 4)= -0.5 이기때문
    # 소수점 4자리까지 표현 해줘야함 원하는 출력 0.5 -> 0.5000

    print(f"{name} {cnt/total*100:.4f}") # :.4f -> 소수점 4자리까지 표현 or 반올림해서 4자리까지 나타내줌

# f.close() # test코드
