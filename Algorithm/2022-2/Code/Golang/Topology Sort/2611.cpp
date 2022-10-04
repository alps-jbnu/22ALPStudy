#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

#define endl "\n"
using namespace std;

//index : 정점, 첫번째int : 연결된 정점, 두번째int : 도로 점수
vector<pair<int, int>> vec[1011];
int indegree[1011];

vector<int> vec_rev[1011];
int score[1011];

vector<int> route[1011];

void TopoSort(int start) {
	queue<int> q;
	q.push(start);
	route[1].push_back(1);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur].at(i).first;
			//이전 값(초기 0, 이전 next값) vs 현재 값(현재 경로의 값)
			//1(0) --(6)--> 5 일 때, cur=1, next=5 score[next] = score[cur] + vec[cur].at(i).second = 0+6
			//2(1) --(3)--> 5		cur=2 , next=5 score[next] = 6 > score[cur] + vec[cur].at(i).second = 1+3
			if (score[next] < score[cur] + vec[cur].at(i).second) {
				score[next] = score[cur] + vec[cur].at(i).second;
				//위 예시에서 1번에서 오는 점수가 더 클 때,
				//1번까지의 경로를 넣은 후
				route[next] = route[cur];
				route[next].push_back(next);
			}
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio, cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;
		vec[p].push_back({q, r});
		vec_rev[q].push_back(p);
		indegree[q]++;
	}
	TopoSort(1);
	cout << score[1] << endl;
	for (int i = 0; i < route[1].size(); i++) {
		cout << route[1].at(i) << " ";
	}
}

/*
문제 : 위상 정렬
1번 지점에서 출발, 1번 지점으로 돌아오기 (중간에는 1번 지나면 안 됨)
다른 지점 출발 - 1번 무조건 통과해야 함
각 도로마다 점수 부여
1번에서 출발하여 가장 많은 점수를 얻어 1번에 도착하는 팀 우승

입력 :
1. 지점의 개수 N (1 ~ N)	
	(1<= N <=1000)
2. 도로의 개수 M
3. 도로 정보  p q r (p지점부터 q지점까지, 도로의 점수는 r)
	(1<= p,q <=N, p != q, 1<= r <=100 자연수)

출력 :
1. 최고 점수
2. 그 때의 경로 (1가지만)
	(1번 지점에서 시작하고 끝나야 함)

풀이 :
1 입력
1-1 N
1-2 for(1~N) -> vec에 입력(단방향)	//0은 사용X
2 위상 정렬 (1번 시작)
2-1 DP : 해당 지점에 가기 위한 최고의 점수(경로) 구하기
2-1-1 이전 지점 점수 중 최댓값 -> 해당 지점의 점수
2-1-2 이전 지점을 알기 위해 간선과 방향이 반대되는 그래프 구현
2-1-2 이전 지점 점수 중 최댓값이 나오는 지점을 경로(vector[i])에 추가(출력? 큐?에 추가)
3 출력
3-1 최고 점수 == 위상 정렬이 끝난 후 1번 지점의 점수
3-2 경로 

질문 :
1. 도로의 점수를 어떻게 넣을까?
->	index : 정점, 첫번째int : 연결된 정점, 두번째int : 도로 점수
	vector<pair<int, int>> vec[1011];
2. 경로를 어떻게 출력할까?
*/