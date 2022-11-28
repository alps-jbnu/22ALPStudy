#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000 + 1
using namespace std;

int N, idx = 0;
int arr[MAX];
int dp[MAX];
vector<int> vec, result;

int Lower_bound(int n)
{
	int left = 0;
	int right = vec.size() - 1;
	
	while(left < right)
	{
		int mid = (left + right) / 2;
		
		if(vec[mid] >= n)
		{
			right = mid;
		}
		else left = mid + 1;
	}
	return left;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	vec.push_back(arr[0]);
	
	for(int i = 1; i < N; i++)
	{
		if(vec[idx] < arr[i])
		{
			vec.push_back(arr[i]);
			idx++;
		}
		else
		{
			int num = Lower_bound(arr[i]);
			vec[num] = arr[i];
		}
	}
	
	cout << N - vec.size();
	
	return 0;
}