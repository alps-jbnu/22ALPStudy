까다로웠던 문제

## [AC](https://www.acmicpc.net/problem/5430)

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 문제

**문제점**  

함수 R을 for문으로 구현할 경우 시간복잡도가 O(N^2)으로 시간초과 발생 (∵ n ≤ 100,000,  p ≤ 100,000)

**해결방안**
1. 함수 R이 호출될 때 현재 배열을 역순으로 출력
2. 함수 R이 호출된 횟수로 출력할 방향을 결정

```cpp
bool P(deque<int> &dq, string p) {
	bool rCnt{};
	for (int i{}; i < p.size(); i++)
	{
		if (p[i] == 'R')
		{
			if (rCnt) rCnt = false;
			else rCnt = true;
		}
		else if (p[i] == 'D' &&dq.size())
		{

			if (rCnt) dq.pop_back();
			else dq.pop_front();
		}
		else return false; //error
	}
	return true;
}
```
