def solution(progresses, speeds):
    answer = [] # 각 배포마다 몇개의 기능이 배포되는지
    remain_day = [] # 남은 개발 기간들
    for i in range(len(progresses)):
        # remain -> 남은 개발 기간
        remain = (100 - progresses[i]) // speeds[i]
        if (100 - progresses[i]) % speeds[i] != 0:
            remain += 1

        remain_day.append(remain) # 먼저 배포되어야 하는 순서대로 남은 개발 기간 저장

    front = remain_day.pop(0)
    # 가장 먼저 배포되어야 하는 기능의 남은 개발 기간을 리스트에서 삭제 후 반환
    prev = front # 리스트의 뒷 내용들과 비교할 대상(현재 가장 남은 개발 기간이 긴 것)
    cnt = 1 # 초기화
    while remain_day: # 리스트에 남은 요소가 없으면 종료
        front = remain_day.pop(0)
        if prev >= front:
            cnt += 1 # 먼저 배포되어야하는 기능이 개발이 더 오래 걸리면 뒤에 기능들이 prev(먼저 배포되어야하는 기능)와 함께 배포됨
        else: # 리스트 체크하다가 더 큰 수 만나면
            answer.append(cnt) # 앞에 기간 짧은 요소들 먼저 배포
            cnt = 1 # 초기화
            prev = front # 비교 대상 새로운 큰 수로 바꾸기 - 뒤에 오는 작은 수들 이 요소와 함께 배포되어야 함

        if not remain_day: # 남은 게 없고 마지막 반복문이라면
            answer.append(cnt) # 마지막 결과까지 리스트에 넣어주기
    return answer

# remain_day = [5, 10, 1, 1, 20, 1]
# pro = [95, 90, 99, 99, 80, 99]
# speed = [1, 1, 1, 1, 1, 1]
# print(solution(pro,speed))
