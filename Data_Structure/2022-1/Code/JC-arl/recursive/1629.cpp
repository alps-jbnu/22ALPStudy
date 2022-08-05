#include<iostream>
using namespace std;

long long POW(long long a, long long b, long long c)
{
	if (b == 1) return a % c;
	long long val = POW(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0)	return val;
	return val * a % c;
}

int main(void)
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
	return 0;
}
