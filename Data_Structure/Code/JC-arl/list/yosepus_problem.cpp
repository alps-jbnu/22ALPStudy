#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	queue<int> qu1, qu2, prt;
	int n, k, count = 0;
	cin >> n >> k;

	for (int j = 1; j <= n; j++)
	{
		qu1.push(j);
	}
	for (int i = 1;; i++)
	{
//1234567
//3 - 124567
//36 - 12457
//362 - 1457
//3627 - 145
		if (qu1.empty() && qu2.empty())
			break;
		if (i % k == 0)
		{
			prt.push(qu1.front());
			//cout <<"prt에 3번째꺼들어감"<<prt.back() << endl;
			qu1.pop();
			count++;
			if (qu1.empty())
			{
				qu1.swap(qu2);

			}
		}
		else {

			qu2.push(qu1.front());
			qu1.pop();
			if (qu1.empty())
			{
				qu1.swap(qu2);

			}
		}
	}
	cout << '<' << prt.front();
	prt.pop();
	for (int j = 1; j < n; j++)
	{
		cout << ", " << prt.front();
		prt.pop();
	}
	cout << '>';
	return 0;
}

/*
입력: 인원n, 제거될 번호 k
출력: 제거되는 번호들의 수열

-끝이 처음과 연결되어서 3번째 마다 해당하는 번호가 제거되고 
제거된 번호는 배열 또는 큐에 넣는다

1.인원n, 제거될 번호 k
1234567

2.




*/