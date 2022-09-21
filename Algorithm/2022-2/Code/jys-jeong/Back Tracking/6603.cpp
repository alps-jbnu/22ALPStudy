#include <bits/stdc++.h>
using namespace std;

int arr[14];
int n;
vector<int> v;
void func(int num, int cur) {

	if (cur == 0) {
		for (int i = 0; i < 6; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i < n - cur+1; i++) {
		v.push_back(arr[i]);
		func(i + 1, cur - 1);
		v.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		fill(arr, arr + n,0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		func(0, 6);
		cout << '\n';
	}
	
	
 }