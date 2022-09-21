#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long d[91] = { 0,1 };
	for (int i = 2; i < 91; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
	
}