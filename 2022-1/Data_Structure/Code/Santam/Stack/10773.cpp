#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		if (temp)
		{
			s.push(temp);
		}
		else
		{
			s.pop();
		}
	}
	int result = 0;
	int size = s.size();
	for (int i = 0;i < size;i++)
	{
		result += s.top();
		s.pop();
	}
	cout << result << endl;
	return 0;
}
/*
1. 0인 경우엔 가장 최근 추가된 숫자를 지우고, 그 외엔 숫자를 더하면 되는 방식 ==> 스택의 구조인 pop,push의 기능으로 구현하면 쉽다고 판단

2. 처음 반복문에서 숫자 n개에 대해 1의 조건을 토대로 구성

3. result에 해당하는 값을 구하기 위해 스택에 남은 데이터를 하나씩 빼가면서 전부 더해주었음
*/