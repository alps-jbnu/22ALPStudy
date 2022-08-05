#include <iostream>
#include <cmath>
using namespace std;

//판의 개수 n, mid 중간 기둥, end 종료 기둥..
void hanoi(int start, int mid, int end, int n) {
	if (n == 1) {
		cout << start << " " << end<< "\n";
	}
	else {
		hanoi(start, end, mid, n - 1);
		cout << start << " " << end << "\n";
		hanoi(mid, start, end, n - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int num = pow(2,n) -1;
	int n;
	cin >> n;
	cout << num << '\n';
	hanoi(1, 2, 3, n);
}