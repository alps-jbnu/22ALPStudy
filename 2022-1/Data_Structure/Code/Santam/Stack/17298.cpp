#include <iostream>
#include <stack>

using namespace std;

int reverse_input[1000000] = { 0 };
int result[1000000] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		reverse_input[n - i - 1] = temp;
	}
	for (int i = 0;i < n;i++)
	{
		while (1)
		{
			if (s.empty())
			{
				result[i] = -1;
				s.push(reverse_input[i]);
				break;
			}
			if (s.top() <= reverse_input[i])
			{
				s.pop();
			}
			else
			{
				result[i]=s.top();
				s.push(reverse_input[i]);
				break;
			}
		}
	}
	for (int i = n - 1;i >= 0;i--)
	{
		cout << result[i] << " ";
	}
}

/*
1. 탑 문제나 옥상정원과 비슷한 유형인듯 싶다. 그래서, 스택을 이용해 입력된 숫자와 기존 스택에 있는 수를 비교하는 방식을 채택했다.

2. 이 문제는 이전 문제들과 다르게 비교를 하면서 pop을 카운터를 해준다거나 위치를 기억할 필요가 없다는 걸 알았다.

3. 입력된 수가 스택의 top보다 크다면 하나씩 pop을 해주었고, 반대의 경우엔 그 값을 저장하도록 했고, 마지막에 저장된 값을 전부 출력했다.
*/