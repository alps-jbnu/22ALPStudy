#include <iostream>
using namespace std;


long long num(long long A, long long B, long long C) {
	if (B == 1) return A % C;
	long long number = num(A, B / 2, C);
	number = number * number %C;
	if (B % 2 == 0) return number;
	return number * A % C;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long A, B, C;
	cin >> A >> B >> C;

	cout << num(A, B,C);
	

}