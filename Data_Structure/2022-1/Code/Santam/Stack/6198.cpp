#include <iostream>
#include <stack>

using namespace std;

long long int index[80001] = { 0 };
long long int reverse_input[80001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	stack<long long int> s;
	long long int result = 0;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		long long int temp;
		cin >> temp;
		reverse_input[n-i-1] = temp;
	}
	for (int i = 0;i < n;i++)
	{
		long long int pop_cnt = 0;
		while(1)
		{
			if (s.empty())
			{
				result += pop_cnt;
				s.push(reverse_input[i]);
				index[s.size()] = pop_cnt;
				break;
			}
			if (reverse_input[i] > s.top())
			{
				pop_cnt += index[s.size()]+1;
				s.pop();
			}
			else
			{
				result += pop_cnt;
				s.push(reverse_input[i]);
				index[s.size()] = pop_cnt;
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}

/*
1. 바로 이전 단계인 탑과 같은 문제라고 생각되어 스택을 이용하여 입력된 값을 스택에 있던 값과 비교해주며 해결

2. 입력된 값보다 작은 값들은 pop을 해주며 카운트를 해주고 입력된 값보다 큰값이 스택의 top에 있으면 카운트한걸 결과에 더해주는 방법

3. 이 문제에서 탑의 높이가 10억까지 된다는 점을 유의할 필요가 있었다고 생각
==> 이걸로 2번 틀렸습니다...
*/