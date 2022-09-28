#include <bits/stdc++.h>
#define MAX 5000 + 1
using namespace std;

int N;
int dp[MAX][MAX], arr[MAX];

int Palindrome(int start, int end)
{
	if (start > end) return 0; // 끝까지 온 케이스

	int& result = dp[start][end];
	if (result != -1) return result;

	if (arr[start] == arr[end]) result = Palindrome(start + 1, end - 1);
	else result = min(1 + Palindrome(start + 1, end), 1 + Palindrome(start, end - 1));

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << Palindrome(0, N - 1);

	return 0;
}