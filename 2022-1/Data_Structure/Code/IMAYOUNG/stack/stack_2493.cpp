#include <iostream>
#include <stack>
#include <utility>
using namespace std;
//스택에서 pair라는 개념 접함.
//<utility> 헤더에 존재.
//주로 x,y 좌표나 이차원 배열의 인덱스 등. 


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack < pair<int, int>> s;
	s.push({ 100000001,0 }); //스택 초기화

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		while (s.top().first < t) {
			s.pop();
		}
		cout << s.top().second << " ";
		s.push({ t, i });

	}

}