#include <iostream>
#include <deque>
using namespace std;

deque<int> a;
int N, M, ans, cnt;
int mNum[51];

void printDQ() {
	for (int i{}; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i{}; i < N; i++)
	{
		a.push_back(i + 1);
	}
	for (int i{}; i < M; i++)
	{
		cin >> mNum[i];
	}
	while (cnt != M)
	{
		int i{};
		for (i; i < N; i++)
		{
			if (a[i] == mNum[cnt]) break;
		}
		if (!i)
		{
			a.pop_front();
			cnt++;
			//printDQ();
		}
		else
		{
			while (a.front() != mNum[cnt])
			{
				if (i > (a.size() - 1) / 2)
				{
					a.push_front(a.back());
					a.pop_back();
				}
				else
				{
					a.push_back(a.front());
					a.pop_front();
				}
				//printDQ();
				ans++;
			}
		}
	}
	cout << ans;
}