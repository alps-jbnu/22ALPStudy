#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 51
#define INF 777
using namespace std;

int N, result = INF;
int Matrix[MAX][MAX];
vector<int> vec;

void Floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			else Matrix[i][j] = INF;
		}
	}

	while (true)
	{
		int x, y;
		cin >> x >> y;
		if (x == -1) break;

		Matrix[x][y] = 1;
		Matrix[y][x] = 1;
	}
	Floyd();

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;

		for (int j = 1; j <= N; j++)
		{
			temp = max(temp, Matrix[i][j]);
		}

		if (temp < result)
		{
			vec.clear();
			result = temp;
			vec.push_back(i);
		}
		else if (temp == result)
		{
			vec.push_back(i);
		}
	}
	sort(vec.begin(), vec.end());

	cout << result << " " << vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}