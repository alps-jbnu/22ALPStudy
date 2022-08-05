#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Pow(ll a, ll b, ll m) {
	if (b == 1) return a % m;
	ll val = Pow(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0)return val;
	else {
		return val * a%m;
	}


}
int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	cout << Pow(a, b, c);
}