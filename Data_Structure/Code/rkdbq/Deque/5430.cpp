#include <iostream>
#include <deque>
using namespace std;

int T;
bool rCnt;

bool P(deque<int> &x, string p) {
	rCnt = 0;
	for (int i{}; i < p.size(); i++)
	{
		if (p[i] == 'R')
		{
			if (rCnt)
			{
				rCnt = false;
			}
			else
			{
				rCnt = true;
			}

		}
		else if (p[i] == 'D' && x.size())
		{

			if (rCnt)
			{
				x.pop_back();
			}
			else
			{
				x.pop_front();
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int j{}; j < T; j++)
	{
		deque<int> x;
		string p{};
		int n{};
		cin >> p;
		cin >> n;

		char temp;
		cin >> temp; //"["
		for (int i{}; i < n; i++)
		{
			int num;
			char trash;
			cin >> num;
			cin >> trash;
			x.push_back(num);
		}
		if (!n) cin >> temp; //"]"
		if (P(x, p))
		{
			cout << "[";
			if (rCnt)
			{
				for (long long i{ x.size() - 1 }; i >= 0; i--)
				{
					if (i) cout << x[i] << ",";
					else cout << x[i];
				}
			}
			else
			{
				for (int i{}; i < x.size(); i++)
				{
					if (i != x.size() - 1) cout << x[i] << ",";
					else cout << x[i];
				}
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
	}
}