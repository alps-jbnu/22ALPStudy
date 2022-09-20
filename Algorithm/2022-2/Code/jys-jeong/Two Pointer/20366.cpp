#include <bits/stdc++.h>
using namespace std;
int arr[605];
int n;
vector<pair< int,pair<int, int>>> t;


int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			t.push_back({ arr[i] + arr[j],{i,j} });
		}
	}
	int mn = INT_MAX;
	sort(t.begin(), t.end());
	for (int i = 0; i < t.size()-1; i++) {
		for (int j = i + 1; j < t.size(); j++) {
			if (t[i].second.first == t[j].second.first)	continue;
			else if (t[i].second.first == t[j].second.second)	continue;
			else if (t[i].second.second == t[j].second.first)	continue;
			else if (t[i].second.second == t[j].second.second)	continue;
			else {
				mn = min(mn, abs(t[i].first - t[j].first));
				break;
			}
		}
	}
	cout << mn;
}
