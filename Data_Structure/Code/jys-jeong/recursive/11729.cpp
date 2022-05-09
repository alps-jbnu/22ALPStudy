#include<bits/stdc++.h>
using namespace std;

void hanoi(int num, int from, int to, int mid) {
	
	if (num == 0)	return;
	hanoi(num - 1, from, mid, to); 
	cout << from << " "<<to << "\n";
	hanoi(num - 1, mid, to, from); 

}


int main() {
	int n;
	cin >> n;
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= 2;
	}
	cout << res - 1 << "\n";
	hanoi(n, 1, 3, 2);
	
 }