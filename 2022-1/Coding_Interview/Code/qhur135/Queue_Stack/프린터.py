def solution(priorities, location):
    answer = 0 # 몇번째로 출력되는지 카운트
    front = -1 # 초기화, 뒤에 우선순위 높은 목록 있나 확인
    tuple_lst = [] # (인덱스, 우선순위) 순으로 저장되어 있는 튜플 리스트
    # [(0,2), (1,1), (2,3), (3,2)]

    for i in range(len(priorities)):
        tuple_lst.append((i, priorities[i]))

    while tuple_lst:
        front = -1 # 초기화
        for j in range(1, len(tuple_lst)): # 리스트 두번째부터 마지막까지 확인
            if tuple_lst[0][1] < tuple_lst[j][1]: # 리스트 맨 앞 요소와 뒤에 있는 나머지 요소들 비교
                front = tuple_lst.pop(0) # 우선순위 높은 목록 있으면 앞에꺼 빼서 뒤에 넣기
                tuple_lst.append(front)
                break

        if front == -1: # 뒤에 우선 수위 높은 목록 없으면 해당 프린트 출력
            print_paper = tuple_lst.pop(0) # 출력
            answer += 1 # 출력할 때마다 카운트
            if print_paper[0] == location: # 알고싶은 문서라면
                break # 종료

    return answer # 몇번째로 출력됐는지

# pr = [2, 1, 3, 2]
# loc = 2
# print(solution(pr,loc))
