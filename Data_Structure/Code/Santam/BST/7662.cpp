#include <iostream>
#include <set>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i <T; i++)
	{
		int input;
		cin >> input;
		multiset<int> s;
		for (int j = 0; j < input; j++)
		{
			char option;
			int n;
			cin >> option >> n;
			if (option == 'I')
			{
				s.insert(n);
			}
			else
			{
				if (s.empty()) continue;
				if (n==1)
				{
					s.erase(--s.end());
				}
				else
				{
					s.erase(s.begin());
				}
			}
		}
		if (s.empty()) cout << "EMPTY\n";
		else cout << *(--s.end()) << " " << *s.begin() << "\n";
	}
}

/*
우선 순위 큐를 구현하기 위해 아진트리 특성인 입력하면 정렬이 되있고 중복으로 들어갈 수 있다는 점에서 multiset을 이용해 구현하면 좋다고 생각
1. 최대값은 multiset의 맨 마지막 원소이고, 최소값은 맨 처음 원소이기에 그점만 생각하고 구현.. 원소를 지우고 나서는 알아서 정렬된다는 건 덤이다
*/