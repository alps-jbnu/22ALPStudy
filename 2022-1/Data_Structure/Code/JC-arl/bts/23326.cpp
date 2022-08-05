#include<iostream>
#include<set>
#include<map>
using namespace std;
set<int> s;

//set<int>::iterator it;
int N, Q;
int pos = 1;
int main(void)
{
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		int c;
		cin >> c;
		if(c==1)
			s.insert(i);
	}
	while (Q--)
	{
		int q;
		cin >> q;

		if (q == 1)
		{
			int at;
			cin>>at;
			if (s.count(at))	s.erase(s.find(at));	
			else	s.insert(at);	
		}
		else if (q == 2)
		{
			int x;
			cin >> x;
			pos += x;
			if (pos % N == 0)
				pos = N;
			else
				pos %= N;
		}
		else if (q == 3)
		{
			int re;
			if (s.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			auto it = s.lower_bound(pos);
			if (it != s.end())
				cout << *it - pos << "\n";
			else
				cout << N - pos + *it << "\n";
			//cout << re;
		}
	}

	return 0;
}