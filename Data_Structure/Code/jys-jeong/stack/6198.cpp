#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	stack<long long> s;
	cin >> n;
	long long sum=0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		for (; !s.empty()&&a>= s.top();) {
			s.pop();
		}
		sum += s.size();
		s.push(a);
		
	}
	cout << sum;
}