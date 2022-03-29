#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		string funt; // 명령내릴 함수
		cin >> funt;

		int num_cnt; // 수열안의 숫자의 수
		cin >> num_cnt;
		
		bool js = true;
		int _reverse = 1;


		char aa1;
		char aa2; // [1~n] 형태의 수열
		
		cin >> aa1;
		deque<int> only_num;// 수열에서 숫자만 모음
		
		for (int i = 0; i < num_cnt; i++)
		{
			int num;
			cin >> num;

			only_num.push_back(num);

			if (i != num_cnt - 1)
			{
				char aa3;
				cin >> aa3;
			}

		}
		cin >> aa2;
		

		for (int i = 0; i < funt.size(); i++)
		{
			if (funt[i] == 'R')
			{
				_reverse++;
				//reverse(only_num.begin(), only_num.end());
			}
			else if (funt[i] == 'D' && _reverse%2 == 1)
			{
				if(!only_num.empty())
				only_num.pop_front();
				else
				{
					js = false;
					break;
				}
			}
			else if (funt[i] == 'D' && _reverse%2==0)
			{
				if (!only_num.empty())
					only_num.pop_back();
				else
				{
					js = false;
					break;
				}
			}
		}

		if (js == true)
		{
			if (_reverse % 2 == 1)
			{
				cout << "[";
				for (int i = 0; i < only_num.size(); i++)
				{
					cout << only_num[i];
					if (i != only_num.size() - 1)
						cout << ",";
				}
				cout << "]" << "\n";
			}
			else
			{
				cout << "[";
				for (int i = only_num.size()-1; i >= 0 ; i--)
				{
					cout << only_num[i];
					if (i != 0)
					cout << ",";
				}
				cout << "]" << "\n";
			}
		}
		
		else
		{
			cout << "error" << "\n";
		}
	}
	
}