#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll result = 0;
	int t;
	cin >> t;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	while (t--) {
		int card;
		cin >> card;
		pq.push(card);
	}


	while (pq.size()>1) { // 입력값 t가 1인 경우 비교안함
		if (pq.size() == 1) break;
		ll first = pq.top();
		pq.pop();

		ll second = pq.top();
		pq.pop();

		ll sum = first + second;
		result += sum; // 합쳐진 임시파일을 매번 더해준다.
		pq.push(sum);  // 합쳐진 임시파일은 pq에 넣어준다
	}
	
	cout << result;

	return 0;
}
