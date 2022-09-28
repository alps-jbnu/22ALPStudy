#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
const int MAX = 200000;

int N, C, result = 0;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int low = 1;
	int high = arr[N - 1] - low;

	while (low <= high)
	{
		int mid = (high + low) / 2;
		int cnt = 1;
		int index = arr[0];

		for (int i = 1; i < N; i++)
		{
			if ((arr[i] - index) >= mid)
			{
				index = arr[i];
				cnt++;
			}
		}

		if (cnt >= C)
		{
			result = mid;
			low = mid + 1;
		}
		else high = mid - 1;

	}

	cout << result << "\n";
	return 0;
}