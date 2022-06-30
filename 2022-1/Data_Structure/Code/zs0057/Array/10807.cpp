#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	int target;
	int cnt = 0;
	cin >> target;
	for (int i = 0; i < n; i++) {
		if (v[i] == target) {
			cnt++;
		}
	}
	cout << cnt;

}
