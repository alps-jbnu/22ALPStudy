#include <iostream>
#include <stack>
using namespace std;

int index[500001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> s;
	int n;
	cin >> n;
	int pop_cnt = 0;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		while (1)
		{
			if (s.empty())
			{
				s.push(temp);
				index[s.size()] = s.size() + pop_cnt;
				cout << "0 ";
				break;
			}
			if (s.top() < temp)
			{
				s.pop();
				pop_cnt++;
			}
			else
			{
				cout << index[s.size()] << " ";
				s.push(temp);
				index[s.size()] = pop_cnt + s.size();
				break;
			}
		}
	}
	return 0;
}

/*
1.입력 값보다 높은 값들 중에 가장 최근에 입력된 것의 위치를 출력하는 것이라고 생각하여 가장 최근에 입력된 값을 찾기 쉬운 스택을 이용

2.n번의 입력에 따라, 만약에 s의 스택이 비어있다면 입력된 값을 스택에 넣어주면서 입력된 값보다 높은 값이 없기에 0을 출력

3.스택에 이미 숫자가 있다면 가장 최근에 입력된 숫자부터 차례로 비교하여 입력된 값보다 작은 값들은 전부 pop
--> 입력된 값보다 작은 값들은 어차피 높은 값들 사이에 가려, 없는 것이나 마찬가지 + 대신,위치를 알기위해 pop한 횟수를 전부 카운트

4.만약 입력된 숫자보다 큰 값이 스택에 존재하면 그값의 위치를 출력하고 입력된 값을 push하면서 입력된 값의 위치를 배열에 저장
*/