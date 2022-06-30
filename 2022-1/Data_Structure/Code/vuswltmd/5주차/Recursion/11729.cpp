#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void func(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << " " << b << '\n';
		return;
	}

	//이 부분 잘 이해가 안 감
	func(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	func(6 - a - b, b, n - 1);
}

int main()
{
	int n;
	cin >> n;

	cout << (1 << n) - 1 << '\n';
	func(1, 3, n);
}
