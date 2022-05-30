#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define Algo 101
#define Difficult 101
using namespace std;

set<int> ques_no_algo[Difficult]; //recommend2에서 알고리즘 분류 없이 최고 난이도의 문제를 알아내기 위한 변수
set<int> ques[Algo][Difficult];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, l, g;
		cin >> p >> l >> g;
		ques[g][l].insert(p);
		ques_no_algo[l].insert(p); 
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (s == "recommend")
		{
			int algorithm_num, option;
			cin >> algorithm_num >> option;
			if (option == 1)
			{
				for (int j = 100; j > 0; j--)
				{
					if (!ques[algorithm_num][j].empty())
					{
						cout << *--ques[algorithm_num][j].end() << "\n";
						break;
					}
				}
			}
			else
			{
				for (int j = 1; j <= 100; j++)
				{
					if (!ques[algorithm_num][j].empty())
					{
						cout << *ques[algorithm_num][j].begin() << "\n";
						break;
					}
				}
			}

		}
		else if (s == "recommend2")
		{
			int option;
			cin >> option;
			if (option == 1)
			{
				for (int j = 100; j > 0; j--)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *--ques_no_algo[j].end() << "\n";
						break;
					}
				}
			}
			else
			{
				for (int j = 1; j <= 100; j++)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *ques_no_algo[j].begin() << "\n";
						break;
					}
				}
			}
		}
		else if (s == "recommend3")
		{
			bool Is_find = false; //찾았는 지의 여부에 대한 플래그
			int difficult_num, option;
			cin >> option >> difficult_num;
			if (option == 1)
			{
				for (int j = difficult_num; j <= 100; j++)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *ques_no_algo[j].begin() << "\n";
						Is_find = true;
						break;
					}
				}
			}
			else
			{
				for (int j = difficult_num - 1; j >= 1; j--)
				{
					if (!ques_no_algo[j].empty())
					{
						cout << *--ques_no_algo[j].end() << "\n";
						Is_find = true;
						break;
					}
				}
			}
			if (!Is_find) cout << -1 << "\n"; //못 찾은 경우
		}
		else if (s == "add")
		{
			int p, l, g;
			cin >> p >> l >> g;
			ques[g][l].insert(p);
			ques_no_algo[l].insert(p);
		}
		else if (s == "solved")
		{
			int p,temp; // p를 찾은 위치의 난이도를 저장하기 위해->ques변수 리스트에 있는 p도 지우기 위해
			cin >> p;
			for (int j = 1; j <= 100; j++)
			{
				auto at=ques_no_algo[j].find(p);
				if (at != ques_no_algo[j].end()) // p를 찾은 경우
				{
					temp = j;
					ques_no_algo[j].erase(at);
					break;
				}
			} // ques_no_algo에 있는 p 제거
			for (int j = 1; j <= 100; j++)
			{
				auto at = ques[j][temp].find(p);
				if (at != ques[j][temp].end()) // p를 찾은 경우
				{
					ques[j][temp].erase(at);
					break;
				}
			} // ques에 있는 p 제거
		}
	}
	return 0;
}
/*
이 문제에 대해서 문제 추천 시스템 1을 참고했는데, 대신 여기에는 알고리즘 분류도 포함되서 set변수 두개를 만들어 알고리즘 분류 유무로 나눠서 둘다 저장했다.
1. ques변수에는 알고리즘 분류별,난이도별에 따라 맞는 배열 위치에 문제번호들을 넣었고, ques_no_algo에는 난이도 별로만 나눠서 넣었다.
2. recommend에서는 입력받은 알고리즘 분류에서 난이도 어려운 순으로 부터 탐색해서 탐색성공한 난이도의 가장 끝에있는 요소(문제번호가 가장 큰곳)을 출력, 반대의 경우엔 반대로
3. recommend2에서는 알고리즘 분류 없는 변수의 2의 과정과 동일하게 진행
4. recommend3에서는 2의 과정에서 난이도를 찾는 반복문의 시작위치만 조절해줬다.
5. solved에서는 ques_no_algo에서 문제번호를 탐색한 위치의 난이도를 찾고(ques에서도 지우기 위해 필요) 해당 요소는 제거,ques에서도 동일 진행(찾아놓은 난이도를 활용)
==> 이 solved에서 시간 복잡도가 클것으로 예상해서 메모아이제이션으로 문제번호랑 난이도를 미리 저장해놓을까도 생각했지만, 그냥 이렇게 해도 시간 초과 안걸리길래 수정안하고 이대로 제출
*/