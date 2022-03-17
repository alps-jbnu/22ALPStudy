#include<iostream>
using namespace std;

int main(void)
{
	int count[10] = { 0 };
	int a, b, c, mul;
	cin >> a >> b >> c;
	mul = a * b * c;
	for (int i = 0; mul > 0; i++)
	{
		count[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << count[i] << "\n";
	

	return 0;
}