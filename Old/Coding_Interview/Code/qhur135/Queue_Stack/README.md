[**다리를 지나는 트럭**](https://programmers.co.kr/learn/courses/30/lessons/42583)   

대기 트럭 &rarr; waitingQ / 다리를 건너는 트럭 &rarr; runningQ   

```
* 함수   
- add_truck() : 다리 위에 트럭 넣어줌   
  - waitingQ의 맨 앞 원소 pop, runningQ에 push하기
  - 다리에 있는 트럭 무게 ++
  - 시간 + 1   
  
- push_truck() : 트럭 밀어줌   
  -> waitingQ에 남은 트럭이 없거나 무게가 초과되어 트럭을 넣어줄 수 없을 때 다리 위 트럭을 밀어주기 위해
  - runningQ 0으로 밀어주기
  - 시간 + 1   
  
- sub_truck() : 다리 위 트럭 빼줌   
  - runningQ pop
  - 다리에 있는 트럭 무게 --   
  
- running_truck() 
  -> 트럭이 앞으로 전진함, 조건이 맞는 경우 새로운 트럭 넣어줌
  - if waitingQ 비어있으면: truck 밀기 (push_truck())
  - else : weight 체크   
    - if 다리 위 트럭 무게 합 <  weight : 다리에 truck ADD (add_truck())
    - else : truck 밀기 (push_truck())   
``` 
**1. runningQ 비어있는 경우**

- if waitingQ도 비어있으면: 종료
- else : 다리에 truck ADD (add_truck())

**2. runningQ 비어있지 않음 & 빈자리 있는 경우**
- running_truck() : 트럭이 앞으로 전진함, 조건이 맞는 경우 새로운 트럭 넣어줌 

**3. runningQ 꽉 찬 경우**

- 다리에서 맨 앞 트럭 빼주기 (sub_truck())
- running_truck() : 트럭이 앞으로 전진함, 조건이 맞는 경우 새로운 트럭 넣어줌 
- if pop한 이후에 다리 맨 앞에 0이 오는 경우 : 맨 앞이 0이 아닐 때까지 pop 
