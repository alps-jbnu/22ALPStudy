#include <iostream>
using namespace std;

int N, V;
int arr[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		int temp{};
		cin >> temp;
		arr[temp + 100]++;
	}
	cin >> V;
	cout << arr[V + 100];

	return 0;
}