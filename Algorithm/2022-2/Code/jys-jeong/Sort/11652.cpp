#include<bits/stdc++.h>
using namespace std;


int n;
long long arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long a, b=0, c=0;// a가 반복되는 수 b가 많이나온 수 중 작은 수 c가 카운팅
	a = arr[0];
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		if (a != arr[i]) continue;
		else {
			while (arr[i] == a&&i<n) {
				++cnt;
				i++;
			}
			if (c < cnt) {
				c = cnt;
				b = arr[i - 1];
			}
			a = arr[i];
			--i;
		}
	}
	cout << b;
}
