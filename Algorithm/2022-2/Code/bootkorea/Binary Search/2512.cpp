#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;
const int MAX = 10000;

int main() {
	int N, M;
	int result = 0;
	int high = 1, mid = 0, low = 0, arr[MAX];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

		high = max(high, arr[i]);
	}

	cin >> M;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			sum += min(arr[i], mid);
		}

		if (sum <= M)
		{
			result = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << result << "\n";

	return 0;
}