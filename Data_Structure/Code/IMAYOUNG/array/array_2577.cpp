#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int num = A * B * C;
	int a[10] = {};

	//10을 나눠서 나머지 수를 인덱스로 사용 
	while (num != 0) {
		a[num % 10]++;
		num /= 10;
	}

	for (int i = 0; i <= 9; i++) {
		cout << a[i] << " ";
	}
}