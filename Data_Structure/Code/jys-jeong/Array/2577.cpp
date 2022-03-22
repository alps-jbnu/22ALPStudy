#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	long long num=1;
	int cnt[10] = { 0 };
	cin >> a >> b >> c;
	num = a * b * c;
	for (; num / 10 != 0;) {
		++cnt[num%10];
		num /= 10;
	}
	++cnt[num];
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << "\n";
}