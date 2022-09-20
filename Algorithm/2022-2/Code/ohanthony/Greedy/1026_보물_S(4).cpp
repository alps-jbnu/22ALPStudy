#include<bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, sum = 0;
	cin >> n;
	
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());		// 오름차순으로 정렬
	sort(b.begin(), b.end(), cmp);  // 내림차순으로 정렬

	for (int i = 0; i < n; i++) sum += a[i] * b[i];
	cout << sum;
	return 0;
}
