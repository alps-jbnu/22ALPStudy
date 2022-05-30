#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>> student;
vector<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		student.push({ a,b });
	}

	while (!student.empty()) {
		int sie = student.top().second;
		student.pop();
		int idx = upper_bound(s.begin(), s.end(), sie, greater<int>())-s.begin();
		if (idx == s.size()) {
			s.push_back(1);
		}
		else
			s[idx]++;	
	}
	cout << s.size();
}