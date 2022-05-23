#include <bits/stdc++.h>
using namespace std;


//멀티셋이나 우선순위 큐 이용하기 ...

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	int t = 0;
	int k = 0;
	char x = 0;
	long long n = 0;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		priority_queue<long long> max;
		priority_queue<long long> min;
		map<long long, int> map; // 중복값도 저장
		for (int j = 0; j < k; j++) {
			cin >> x >> n;
			if (x == 'D') {
				if (!map.empty()) {
					if (n == 1) { // 최댓값 삭제
						while (!max.empty() && map[max.top()] == 0) {
	
							max.pop();
						}

						if (!max.empty()) {
							map[max.top()]--;
							max.pop();
						}
					}
					else { // 최솟값 삭제
						while (!min.empty() && map[-min.top()] == 0) {

							min.pop();
						}

						if (!min.empty()) {
							map[-min.top()]--;
							min.pop();
						}
					}
				}
			}
			else {
				map[n]++;
				max.push(n);
				min.push(-n);
			}
		}
		// 요 두개의 while문이 있어야 맞음
		while (!max.empty() && map[max.top()] == 0) {
			// 맵에 없는 원소들은 삭제
			max.pop();
		}
		while (!min.empty() && map[-min.top()] == 0) {
			// 맵에 없는 원소들은 삭제
			min.pop();
		}
		if (max.empty() || min.empty()) {
			cout << "EMPTY\n";
		}
		else cout << max.top() << " " << -min.top() << "\n";
	}


	return 0;
}