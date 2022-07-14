옥상 정원 꾸미기
=====================================
건물의 관리인들이 벤치 마킹이 가능한 빌딩의 수의 합을 구하는 문제이다. 
-------------------------------------

#1. 해결방법
> 두 번째 건물부터 현재 건물보다 작은 건물들을 다 빼준다.
> 건물을 빼주면, 스택에 있는 개수만큼 더해주고 해당 건물들을 스택에 다시 넣는다. 

#2. 코드
<pre><code>{#include <iostream>
#include <stack>
using namespace std;

//주의할 점: n이 80,000,, -> long long

//스택에 빌딩이 있을 때, 
//1, 이전 빌딩이 새 빌딩보다 높으면 이전 빌딩에서 관측 가능
//2. 이전 빌딩이 새 빌딩보다 낮으면 이전 빌딩에서 관측 불가
//관측 불가한 빌딩은 버리기
//스택에 남아있는 빌딩들이 관측 가능 빌딩 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;

	long long sum = 0;
	int n;
	int t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		while (!s.empty()) {
			if (s.top() > t) break;
			s.pop();
		}
		sum += (long long)s.size();
		s.push(t);
	}

	cout << sum << "\n";
	return 0;



}}</code>

#3. 어려웠던 점
문제 이해는 어렵지 않았으나, 어떻게 구현해야할지 막막하였음. 전 문제인 '탑' 문제가 유사하여 응용함. 
