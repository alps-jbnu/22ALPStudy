waitingQueue = []  # 대기 트럭
runningQueue = []  # 건너는 트럭
sum = 0  # 트럭 무게
answer = 0
def running_truck(weight): # 앞으로 전진, 조건 맞는다면 새로운 트럭 넣어줌
    if not waitingQueue:
        push_truck()  # 0으로 밀어주기
    else:
        test = sum + waitingQueue[0]
        if test <= weight:
            add_truck(waitingQueue.pop(0))
        else:  # 무게 다 찼으면 0으로 밀어주기
            push_truck()
def add_truck(truck_weights): # 다리에 새로운 트럭 넣어주기
    global sum, answer
    sum = sum + int(truck_weights)  # 다리에 있는 트럭 무게 계산
    runningQueue.append(truck_weights) # 다리에 트럭 넣기
    answer = answer + 1 # 시간 흐름
def push_truck(): # 밀어주기
    global answer
    runningQueue.append(0)
    answer = answer + 1
def sub_truck(): # 맨 앞 트럭 빼주기
    global sum
    finish_truck = runningQueue.pop(0)
    sum = sum - int(finish_truck)

def solution(bridge_length, weight, truck_weights):
    global sum
    for w in truck_weights:
        waitingQueue.append(w)

    while 1:
        if not runningQueue: # 다리에 트럭이 없으면 # 대기 트럭 넣어주기
            if not waitingQueue: # 모든 트럭이 지나갔다면 종료
                break
            add_truck(waitingQueue.pop(0))
        elif len(runningQueue) < bridge_length: # 다리에 빈자리 있는 경우 # 넣어줄 수 있는지 조건 체크
            running_truck(weight) # 전진
        elif len(runningQueue) == bridge_length: # 큐가 꽉찬경우
            sub_truck() # 빼주고
            running_truck(weight) # 전진
            while 1: # 맨 앞에 0이 없을 때까지 pop
                if not runningQueue:
                    break
                front = runningQueue[0]
                if front!=0:
                    break
                runningQueue.pop(0)
    # print(answer)
    return answer
# length = 100
# weight = 100
# trucks = [10,10,10,10,10,10,10,10,10,10]
# solution(length, weight, trucks)
