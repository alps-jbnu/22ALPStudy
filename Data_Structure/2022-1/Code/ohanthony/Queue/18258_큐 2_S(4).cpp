#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, k; // n: 명령의 수, k : queue에 집어넣을 수
string ptr;
queue<int> q;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> ptr;

		if (ptr == "push")
		{
			cin >> k;
			q.push(k);
		}
		else if (ptr == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << -1 << "\n";
			
		}
		else if (ptr == "size")
		{
			cout << q.size() << "\n";
		}
		else if (ptr == "empty")
		{
			cout << q.empty() << "\n";
		} 
		else if (ptr == "front")
		{
			if (!q.empty())
				cout << q.front() << "\n";
			else cout << -1 << "\n";
		}
		else 
		{
			if (!q.empty())
				cout << q.back() << "\n";
			else cout << -1 << "\n";
		}
	}
	
	return 0;
}