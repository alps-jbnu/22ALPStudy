#include bitsstdc++.h
using namespace std;


int n;
long long arr[5005];


int main() {
	iossync_with_stdio;
	cin.tie(0);
	cin  n;
	for (int i = 0; i  n; i++) {
		cin  arr[i];
	}
	sort(arr, arr + n);
	long long a = 1000000001, b = 1000000001, c = 1000000001;
	for (int i = 0; i  n; i++) {
		for (int j = i + 1; j  n; j++) {
			int idx = lower_bound(arr, arr + n, -(arr[i] + arr[j])) - arr;
			if (idx  n && idx != i && idx != j && abs(arr[i] + arr[j] + arr[idx])  abs(a + b + c)) {
				a = arr[i];
				b = arr[j];
				c = arr[idx];
			}
			if (idx + 1  n && idx + 1 != i && idx + 1 != j && abs(arr[i] + arr[j] + arr[idx + 1])  abs(a + b + c)) {
				a = arr[i];
				b = arr[j];
				c = arr[idx + 1];
			}
			if (idx != 0 && idx - 1 != i && idx - 1 != j && abs(arr[i] + arr[j] + arr[idx - 1])  abs(a + b + c)) {
				a = arr[i];
				b = arr[j];
				c = arr[idx - 1];
			}
		}
	}
	long long q[3] = { a,b,c };
	sort(q, q + 3);
	cout  q[0]  ' '  q[1]  ' '  q[2];


}