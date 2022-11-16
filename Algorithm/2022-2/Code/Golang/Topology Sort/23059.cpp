#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 400011
using namespace std;
typedef pair<int, int> pi;

unordered_map<int, string> intToString;
unordered_map<string, int> stringToInt;
vector<int> graph[MAX], ans[MAX];
int indegree[MAX];
int N, j;

bool cmp(int a, int b) {
	return intToString[a] < intToString[b];
}

void print() {
	for (int i = 0; ; i++) {
		if (!ans[i].size()) return;

		sort(ans[i].begin(), ans[i].end(), cmp);
		for (int j = 0; j < ans[i].size(); j++) {
			cout << intToString[ans[i][j]] << '\n';
		}
	}
}

void TopoSort() {
	queue<pi> q;
	for (int i = 0; i < j; i++) {
		if (!indegree[i]) {
			q.push({ i,0 });
			ans[0].push_back(i);
		}
	}

	for (int t = 0; t < j; t++) {
		if (q.empty()) {
			cout << "-1\n";
			return;
		}

		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			indegree[next]--;

			if (!indegree[next]) {
				q.push({ next, cnt + 1 });
				ans[cnt + 1].push_back(next);
			}
		}
	}

	print();
}

int main() {
	ios::sync_with_stdio, cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		//string <-> int
		if (stringToInt.find(s1) == stringToInt.end()) {
			stringToInt.insert({ s1, j });
			intToString.insert({ j++, s1 });
		}
		if (stringToInt.find(s2) == stringToInt.end()) {
			stringToInt.insert({ s2, j });
			intToString.insert({ j++, s2 });
		}
		graph[stringToInt[s1]].push_back(stringToInt[s2]);
		indegree[stringToInt[s2]]++;
	}
	TopoSort();
}
/*
문제 :
아이템 사이에 미리 정해진 구매 순서 존재 (2개 선후관계)
1) 현재 구매할 수 있는 아이템 중 아직 구매하지 않은 아이템을 모두 찾는다.
2) 찾은 아이템을 사전 순으로 모두 구매한다
다음 과정을 반복하여 아이템을 구매할 때, 아이템의 전체 구매 순서를 알아내자.

입력 :
1. 아이템 관계 수 N
	(1 ≤ N ≤ 200000)
2. 아이템이름 A(선) B(후)
	(A!=B, 1<=이름(string)<=15)

출력 :
1. 먼저 구매해야 하는 아이템부터 순서대로 각 줄에 걸쳐 출력
1-1. 모든 아이템을 구매할 수 없다면 -1 출력

풀이 :
1. string <-> int 변환 (양방향으로 변환이 가능해야 함)
2. 그래프 만들기 -> 위상 정렬
3. 사전 순 입력

질문 :
1. 사전 순서대로 출력하려면?
-> 벡터에 넣고 벡터를 정렬함
* vector<pair<int, string>> 을 이용하면 좋을 듯함. 정렬 시 int -> string 순으로 자동 정렬되기 떄문.

2. 입력 값이 모두 string일 때, 그래프를 어떻게 구현해야 하나?
->	unordered_map을 이용
	unordered_map<int, string> intToString;
	unordered_map<string, int> stringToInt;
	stringToInt.insert({ s1, j });
	intToString.insert({ j++, s1 });

시간복잡도 :

*/