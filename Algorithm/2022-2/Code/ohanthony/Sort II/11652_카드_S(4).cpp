#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long

ll result;
map<ll, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, max = 0;

	cin >> n;
	while(n--){
		ll card;
		cin >> card;
		m[card]++;
	}

	for (auto nxt : m) {
		if (nxt.second > max) {
			max = nxt.Y;
			result = nxt.X; // map은 알아서 오름차순으로 정리되므로 따로 정렬할 필요없다.
		}
	}

	cout << result;

	return 0;
}
