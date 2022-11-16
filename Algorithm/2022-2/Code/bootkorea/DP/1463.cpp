#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	int Data[1000001] = { 0, };
	cin >> num;

	Data[1] = 0;

	for (int i = 2; i <= num; i++)
	{
		Data[i] = Data[i - 1] + 1;
		if (i % 2 == 0)
		{
			Data[i] = min(Data[i], Data[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			Data[i] = min(Data[i], Data[i / 3] + 1);
		}
	}

	cout << Data[num];
	return 0;
}