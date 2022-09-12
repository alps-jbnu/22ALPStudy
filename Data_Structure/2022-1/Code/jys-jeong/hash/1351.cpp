#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
unordered_map<long long, long long> m;
long long p, q;
long long solve(long long n) {
	
	
	if (m[n] != 0)	return m[n];

	return m[n] = solve(n / p) + solve(n / q);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	long long n;
	cin >> n >> p >> q;
	m.insert({ 0,1 });
	cout << solve(n);
}