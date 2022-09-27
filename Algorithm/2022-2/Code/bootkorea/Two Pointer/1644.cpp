#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 4000000 + 1
typedef long long ll;
using namespace std;

int N;
bool arr[MAX];
vector<ll> vec;

int main()
{
	cin >> N;
	memset(arr, 1, sizeof(arr));

	for (ll i = 2; i < MAX; i++)
	{
		if (arr[i] == true)
		{
			vec.push_back(i);
		}

		for (ll j = i * 2; j < MAX; j += i)
		{
			arr[j] = 0;
		}
	}

	int left = 0, right = 0; // 투 포인터
	int sum = vec[0]; // 합해서 나오는 값을 구하기 위한 sum 변수
	int result = 0; // 결과값

	while (left <= right && right < vec.size() - 1) // 반복문 조건
	{
		if (sum < N)
		{
			if (right < vec.size() - 1)
			{
				right++;
				sum += vec[right];
			}
		}

		if (sum > N)
		{
			if (left <= right)
			{
				sum -= vec[left];
				left++;
			}
		}

		if (sum == N)
		{
			if (right < vec.size() - 1)
			{
				right++;
				sum += vec[right];
			}
			result++;
		}
	}

	cout << result;

	return 0;
}