#include<iostream>
using namespace std;

int N;
string arr[70];

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (arr[x][y] != arr[i][j])
				return false;
	return true;
}

void Quad_Tree(int x,int y, int z)
{
	if (check(x, y, z))
	{
		cout << arr[x][y];
		return;
	}
	cout << "(";
	int n = z / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			Quad_Tree(x + i * n, y + j * n, n);
	cout << ")";
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Quad_Tree(0, 0, N);

	return 0;
}