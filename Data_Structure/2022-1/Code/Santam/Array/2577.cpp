#include <iostream>

using namespace std;

int main()
{
	int num[10] = { 0 };
	int a, b, c;
	cin >> a; cin >> b; cin >> c;
	long int temp = a * b * c;
	for (int i = 1;(temp-i)>=0;i=i*10)
	{
		num[(temp / i) % 10]++;
	}
	for (int i = 0;i < 10;i++)
	{
		cout << num[i] << '\n';
	}
	return 0;
}