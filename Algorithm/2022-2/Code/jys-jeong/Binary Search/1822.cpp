#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> arr1;
vector<int> ans;
int k,n;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		arr1.push_back(a);
	}
	sort(arr1.begin(), arr1.end());
	for (int i = 0; i < n; i++) {
		if (!binary_search(arr1.begin(), arr1.end(), arr[i])) {
			ans.push_back(arr[i]);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	if (ans.size() == 0) { return 0; }
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}
