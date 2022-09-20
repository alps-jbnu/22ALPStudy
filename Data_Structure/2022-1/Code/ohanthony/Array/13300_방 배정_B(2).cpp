#include<bits/stdc++.h>
using namespace std;

int arr[2][7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, y, s; 
	int count = 0;
	// n: 참가하는 학생 수 
	// k: 한 방에 배정할 수 있는 최대 인원 수
	// y: 학년
	// s: 성별

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;
		arr[s][y]++;
	}
		
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (arr[i][j] != 0)
			{
				if (arr[i][j] < k)
				{
					count++;
				}
				else
				{
					if (arr[i][j] % k != 0) count += arr[i][j] / k + 1;
					else
					{
						count += arr[i][j] / k;
					}
				}
			}
			
		}
	}

	cout << count;
	return 0;
}