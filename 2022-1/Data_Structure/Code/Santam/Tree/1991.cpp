#include <iostream>

using namespace std;

char lc[26] = { 0 };
char rc[26] = { 0 };

void Pre(int n)
{
	cout << char(n+'A');
	if (lc[n] > 0) Pre(lc[n]);
	if (rc[n] > 0) Pre(rc[n]);
}

void Ino(int n)
{
	if (lc[n] > 0) Ino(lc[n]);
	cout << char(n + 'A');
	if (rc[n] > 0) Ino(rc[n]);
}

void Post(int n)
{
	if (lc[n] > 0) Post(lc[n]);
	if (rc[n] > 0) Post(rc[n]);
	cout << char(n + 'A');
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp[3] = { 0 };
		for (int j = 0;j < 3;j++)
		{
			char num;
			cin >> num;
			if (num - 'A' >= 0) temp[j] = num - 'A';
		}
		lc[temp[0]] = temp[1];
		rc[temp[0]] = temp[2];
	}
	Pre(0);
	cout << "\n";
	Ino(0);
	cout << "\n";
	Post(0);
	return 0;
}