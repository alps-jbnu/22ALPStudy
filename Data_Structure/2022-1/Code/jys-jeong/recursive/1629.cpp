#include<bits/stdc++.h>
using namespace std;




long long pow(long long a, long long b, long long c) {

	if (b == 1)	return a % c;
	long long res = pow(a, b / 2, c);
	if (b % 2 == 0)	return res * res % c;
	return res * res % c * a % c;

}


int main() {

	long long a, b, c, cnt = 0;
	long long res = 1;

	cin >> a >> b >> c;
	
	cout << pow(a, b, c);
 }