#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--)
	{
		vector<int> A;
		vector<int> B;
		int a, b;
		int count = 0;
		cin >> a >> b;

		for (int i = 0; i < a; i++)
		{
			int num;
			cin >> num;

			A.push_back(num);
		}

		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		//A.erase(unique(A.begin(), A.end()), A.end());

		for (int i = 0; i < b; i++)
		{
			int num;
			cin >> num;

			for (int i = 0; i < A.size(); i++)
			{
				if (num < A[i])
				{
					count++;
				}
				else
				{
					break;
				}
			}
		}

		cout << count << '\n';

		//sort(B.begin(), B.end());
		////B.erase(unique(B.begin(), B.end()), B.end());

		//for (int i = 0; i < A.size(); i++)
		//{
		//	for (int j = 0; j < B.size(); j++)
		//	{
		//		if (A[i] > B[j])
		//		{
		//			count++;
		//		}
		//	}
		//}

		

		A.clear();
		B.clear();
	}
}