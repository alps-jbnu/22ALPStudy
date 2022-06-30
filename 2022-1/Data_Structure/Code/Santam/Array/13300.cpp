#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n; cin >> k;

	int student[2][7] = { 0 };

	for (int i = 0;i < n;i++)
	{
		int s;
		int y;
		cin >> s; cin >> y;
		student[s][y]++;
	}
	int room = 0;

	for (int i = 0;i < 2;i++)
	{
		for (int j = 1;j < 7;j++)
		{
			int temp = student[i][j] / k;
			if ((student[i][j] - k * temp) > 0) room += temp + 1;
			else room += temp;
		}
	}
	cout << room << endl;
	return 0;
}