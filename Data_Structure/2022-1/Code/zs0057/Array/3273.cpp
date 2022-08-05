#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL);

	int n;
	cin >> n;
	int a = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int l = 0;
	int r = n - 1;
	int cnt = 0;

	int x = 0;
	cin >> x;
	while (1) {
		if (l >= r) {
			break;
		}
		if (v[l] + v[r] == x) {
			cnt++;
			l += 1;
			r -= 1;
		}
		else if (v[l] + v[r] > x) {
			r -= 1;
		}
		else if (v[l] + v[r] < x) {
			l += 1;
		}
	}
	cout << cnt;
}
