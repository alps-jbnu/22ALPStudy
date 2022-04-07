import heapq
max_heap = [] # - 붙여서 push
min_heap = [] # heapq min heap임
remove_lst = []
# 최대힙, 최소힙 채우기
def push_2heap(l,p):
    heapq.heappush(max_heap, (-l, -p))  # 최대힙
    heapq.heappush(min_heap, (l, p))  # 최소힙
# 명령어 수행하기
def recommend_operate(heap):
    l, p = heap[0]
    if p<0: # 최대힙일 경우 - 붙여야 실제 문제 번호 나옴
        p = -p
    # remove_lst 참고해서 이미 지운 문제라면 출력하지 않고 지워주도록
    while p in remove_lst: # 지운 문제라면 처리
        if (l, p) in multi_problem:  # 새로운 문제정보라면 지우지 말기!
            break
        remove_lst.remove(p) # 실제로 지울거 지움
        heapq.heappop(heap)
        l, p = heap[0]
        if p < 0:
            p = -p
    return p

# 추천 문제 리스트
n = int(input())
for i in range(n):
    p, l = input().split(' ') # 문제번호, 난이도
    p = int(p)
    l = int(l)
    push_2heap(l,p)

# 명령문
m = int(input())
multi_problem = []
for i in range(m):
    command = input().split(' ')
    choice = command[0]
    if choice=='add':
        p = int(command[1])
        l = int(command[2])
        if p in remove_lst: # 지운 문제를 다시 넣는 경우
            multi_problem.append((l, p)) # 새로운 문제 정보 저장해두기
        push_2heap(l,p)
    elif choice=='recommend':
        level = command[1]
        if level=='1':
            result = recommend_operate(max_heap)
            print(result)
        elif level=='-1':
            result = recommend_operate(min_heap)
            print(result)
    elif choice=='solved':
        remove = int(command[1])
        remove_lst.append(remove) # 지운문제번호 저장
