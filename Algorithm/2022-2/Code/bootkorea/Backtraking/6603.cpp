#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K, arr[6];
vector<int> vec;

void DFS(int s, int e)
{
	if (e == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = s; i < K; i++)
	{
		arr[e] = vec[i];
		DFS(i + 1, e + 1);
	}
}

int main()
{
	while (true)
	{
		cin >> K;
		if (K != 0)
		{
			vec.resize(K);
			for (int i = 0; i < K; i++)
			{
				cin >> vec[i];
			}

			DFS(0, 0);
			cout << "\n";
		}
		else break;
	}

	return 0;
}