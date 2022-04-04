## [Condition of deep sleep](https://www.acmicpc.net/problem/11577)

관련 아이디어 : [1080](https://www.acmicpc.net/problem/11577)  
greedy하게 뒤집는 발상이 비슷함  
N, K 의 제한이 매우 크기 때문에 뒤집을 때 마다 갱신하는게 아닌 Queue를 사용하여 몇 번째 전구까지 뒤집었는지 기록  
임의의 i번 째 전구에서, Queue의 크기가 짝수이면 상태 유지, 홀수이면 flip

## [데이터 체커](https://www.acmicpc.net/problem/22942)

생각보다 오래 걸린 문제  
원을 점들의 쌍 (시작, 끝) 이라고 생각하고, 이 점들이 겹치지 않게 배열하는 문제  
무슨 말이냐 --> a0 = (l0, r0), a1 = (l1, r1) 을 가정하면, l1 < l0 < r0 < r1 이라면 상관 x, l1 < l0 < r1 < r0 인 상태는 문제상황  
이러한 상황을 찾아내자

이 때, 점들을 시작점 기준 오름차순으로 정렬 후, stack을 사용해서 top.right < curr.left 라면 모두 pop -> 겹칠 가능성이 zero

--> 세그 트리로도 풀림, r을 기준으로 내림차순 정렬 후 sum트리로 해결
