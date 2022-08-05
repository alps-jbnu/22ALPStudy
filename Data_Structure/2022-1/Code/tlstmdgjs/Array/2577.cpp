#include<bits/stdc++.h>
using namespace std;

int freq[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A, B, C;
	cin >> A >> B >> C;
	int N = A * B * C;

	while (N > 0) {
		freq[N % 10]++;
		N = N / 10;
	}
	for (int i = 0; i < 10; i++)
		cout << freq[i] << "\n";
}