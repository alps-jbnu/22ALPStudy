## [N으로 만들기](https://noj.am/17255)

N의 범위가 0 <= N <= 10,000,000 이라 큰 줄 알았지만, 이를 문자열으로 처리하면 최대 8개의 문자  
현재 수를 curr이라 할 때 \forall n \in [0, 10] n + curr, curr + n 수행  
수행한 문자열이 입력 문자열 안에 존재하면 재귀를 수행  (ex, if n + curr in input_string, recurssion(n + curr), end)  

이 때 주의해야 할 점은 **숫자를 적는 과정에서 나온 수가 순서대로 모두 같다면 같은 방법이다.**
현재 상태를 curr, 현재 수를 n 이라 할 때, 같은 과정은 수행하는 경우는 curr + n == n + curr 일 때 뿐이다.  
이는 visited를 사용해 예외처리 해줌  


## [싸지방에 간 준하](https://noj.am/12674)
처음에는 틀렸는데, 예외 (end time, seat number) 를 기준으로 우선순위를 잡았음.  
만약, end time이 더 높은데 seat number이 더 낮다면 이 자리를 선택해야함.  
이를 위해 remain, using 2개의 우선순위 큐 사용  