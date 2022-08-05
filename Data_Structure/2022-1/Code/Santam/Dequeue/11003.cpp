#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<pair<int, int>> d_min;
	int n, l, cnt = 0;
	cin >> n >> l;


	while (cnt < n)
	{
		int temp;
		cin >> temp;
		while (d_min.size()!=0)
		{	
			if (d_min.back().first <= temp)
			{
				pair<int, int> p = { temp,cnt };
				d_min.push_back(p);
				break;
			}
			d_min.pop_back();
		}
		if(d_min.size()==0)
		{
			pair<int, int> p = { temp,cnt };
			d_min.push_back(p);
		}

		if (cnt >= l)
		{
			if (d_min.front().second == cnt - l) d_min.pop_front();
		}

		cout << d_min.front().first << " ";

		cnt++;
	}

	return 0;
}

/*
1.처음에 전체 입력 구간 중 일부만을 저장할 덱1과 입력 된 값을 오름차순 순서대로 받아올 덱2를 만들어 구간의 영역을 벗어나는 숫자가 제거되면 동시에 두 덱에 있던 같은 숫자를 제거하려고 했으나 시간복잡도가 커진다는 것을 깨달았다.

2.따라서 두 덱을 하나의 덱으로 합쳐주기 위한 방법을 몰색했고,pair가 그 역할을 해주리라는 생각으로 사용했다.

3.먼저, 일부를 저장할 덱의 size가 0이면 무조건적 입력을 받도록 해주었다. 그렇지 않을때는 오름차순으로 숫자를 정렬하기위해 기존의 덱에 있는 수와 비교해서 입력값을 push했다.
==> 여기서, 처음에는 덱에 있는 숫자를 보존하기 위해 노력했는데, 사실, 구간 내의 최소값만 출력하는 문제였기에, 입력되는 값보다 큰 값이 덱안에 있다면, 결단코 그 값이 최소값이 될 수 없다는 걸 확신할 수 있어서, 따로, pop해주고 보존하지 않았다.

4.만약에 구간의 영역에서 벗어나는 수는 cnt가 l보다 클때마다 매번 생기므로, 이 조건을 토대로, c-l에 해당하는 위치를 가진 덱 안의 값을 제거했다.
*/