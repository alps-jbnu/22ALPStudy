#include <iostream>
#include <string>
using namespace std;

int A, B, C;
int ans[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C;
	A = A * B * C;
	//cout << A << endl;
	string num{};
	num = to_string(A);
	//cout << num << endl;
	for (int i{}; i < num.size(); i++) {
		//cout << num[i] << endl;
		ans[num[i] - '0']++;
	}
	for (int i{}; i < 10; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}