## [Condition of deep sleep](https://www.acmicpc.net/problem/11577)
관련 아이디어 : [1080](https://www.acmicpc.net/problem/11577)
greedy하게 뒤집는 발상이 비슷함
N, K 의 제한이 매우 크기 때문에 뒤집을 때 마다 갱신하는게 아닌 Queue를 사용하여 몇 번째 전구까지 뒤집었는지 기록
임의의 i번 째 전구에서, Queue의 크기가 짝수이면 상태 유지, 홀수이면 flip

