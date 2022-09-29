#include <iostream>
#define MAX 100000 + 1
using namespace std;

int N, M, Start, End;
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> Start >> End;

		if (Start == 0) cout << arr[End] << "\n";
		else cout << arr[End] - arr[Start - 1] << "\n";
	}

	return 0;
}