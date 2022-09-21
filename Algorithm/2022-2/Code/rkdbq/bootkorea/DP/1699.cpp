#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define ll long long
const int MAX = 100000 + 1;
using namespace std;

int N;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	cout << arr[N];

	return 0;
}