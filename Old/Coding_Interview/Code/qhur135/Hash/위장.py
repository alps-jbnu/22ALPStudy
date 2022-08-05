from collections import defaultdict

def solution(clothes):
    answer = 0
    clothes_dic = defaultdict(int) # 딕셔너리 만들기, value 0으로 세팅
    for element in clothes: # element : ["crowmask", "face"]
        type = element[1] # type "face"
        clothes_dic[type]+=1 # 타입 별로 카운트

    value_lst = []

    for key in clothes_dic: # key(type) "face"
        value_lst.append(clothes_dic[key]) # type 별 옷 개수

    case = 1 # 경우의 수 카운트
    for num in value_lst: # headgear:3종류, eyewear:2종류, jacket:4종류라면
        # -> (headgear 종류 중 하나 입거나 안입는 경우 4가지, eyewear중 하나 입거나 안입는 경우 3가지....) 4 * 3 * 5 - 1(아무것도 안입는경우 제외)
        case*=(num+1)

    answer = case-1 # 아무것도 안입는 경우 제외(문제 조건, 적어도 하나는 입어야함)

    # print(answer)
    return answer

# clo = [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"], ["red_clothes","clothes"]]
# solution(clo)
