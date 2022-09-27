#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

void func(int start, int end, int n){
	if(n == 1) {
		cout << start  << ' ' << end << '\n';
		return ;
	}

	func(start, 6 - start - end, n-1);
	cout << start  << ' ' << end << '\n';
	func(6-start-end, end, n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	cout << (1<<n)-1 << "\n";
	func(1, 3, n);
	return 0;
}
