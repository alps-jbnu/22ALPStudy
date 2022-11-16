#include<bits/stdc++.h>
using namespace std;
int arr[1000004];
vector<int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans.push_back(arr[i]);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < n; i++) {
		cout << lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin() << ' ';
	}
}