#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int arr[1000005];
int n;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (vec.empty() || vec.back() < arr[i]) {
			vec.push_back(arr[i]);
		}
		else {
			int st = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
			vec[st] = arr[i];
		}
	}
	
	cout << vec.size();
	
}
