까다로웠던 문제

## [이분 그래프](https://www.acmicpc.net/problem/1707)

입력으로 주어진 그래프가 [이분 그래프](https://ko.wikipedia.org/wiki/%EC%9D%B4%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84)인지 아닌지 판별하는 문제

**주의점**  

1. 노드 방문 여부를 true || false 로 저장하면 해결 불가능
2. 그래프(컴포넌트)가 여러 개인 경우 고려
3. 간선을 인접행렬에 저장 시 공간복잡도가 O(V^2)(V ≤ 20,000)이므로 메모리 초과

**해결방안**
1. 노드 간 최단경로 별로 적절한 vis값 저장
2. 각 컴포넌트의 첫 원소를 큐에 저장
3. 인접리스트에 간선 저장

```cpp
void bfs(){
	while (!Q.empty()) {
		int cur{ Q.front() };
		Q.pop();
		if (lis[cur].size() == 0) vis[cur] = -1;
		for (int i{}; i < lis[cur].size(); i++) {
			int nxt{ lis[cur][i] };
			if (vis[nxt] != 0) continue;
			dis[nxt] = dis[cur] + 1;
			if (dis[nxt] % 2 == 1) vis[nxt] = 1;
			else vis[nxt] = -1;
			Q.push(nxt);
		}
	}
}
```
