#include <iostream>
#include <set>

using namespace std;


int main()
{
	set<int> ques[101];
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, l;
		cin >> p >> l;
		ques[l].insert(p);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int p, l;
			cin >> p >> l;
			ques[l].insert(p);
		}
		else if (s == "recommend")
		{
			int option;
			cin >> option;
			if (option == 1)
			{
				for (int i = 100;i >= 1;i--)
				{
					if (!ques[i].empty())
					{
						cout << *(--ques[i].end()) << "\n"; break;
					}
				}
			}
			else
			{
				for (int i = 1;i <= 100;i++)
				{
					if (!ques[i].empty())
					{
						cout << *ques[i].begin() << "\n"; break;
					}
				}
			}
		}
		else
		{
			int sol;
			cin >> sol;
			for (int i = 100;i >= 1;i--)
			{
				auto at = ques[i].find(sol);
				if (at!= ques[i].end())
				{
					ques[i].erase(at);
					break;
				}
			}
		}
	}
}
/*
먼저 이문제 map써서 저장한다음 풀려했지만, 난이도찾을때 어려울거 같아서 set써서 풀었다.
1. set에 대한 배열 변수로 설정 배열의 인자로 들어올 값은 난이도이다.
2. set에 각 각 난이도 별로 문제번호를 insert하면 자동으로 정렬이 되어있다.
3. add는 그냥 값을 넣어주기만 하면되고, recoomand에서 최대난이도의 최대 번호 문제를 출력할땐 set배열 끝에서부터 탐색하면서
set이 비어있지 않으면 그 set의 끝에있는 요소를 출력, 최소라면 반대로 set배열 처음에서부터 탐색, set처음의 원소 출력
4. solve에서 해당 문제번호를 리스트에서 삭제해야되므로, set배열 전체를 탐색하면서 해당 문제 삭제
*/