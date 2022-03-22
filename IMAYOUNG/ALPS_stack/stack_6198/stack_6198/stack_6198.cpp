#include <iostream>
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



}