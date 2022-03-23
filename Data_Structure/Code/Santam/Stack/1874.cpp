#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int> s;
	vector<string> v;
	bool chk_no = false;
	int n;
	cin >> n;
	int n_state = 1;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		if (temp >= n_state)
		{
			for (int j = n_state;j <= temp;j++)
			{
				s.push(j);
				v.push_back("+");
			}
			n_state = s.top()+1;
			v.push_back("-");
			s.pop();
		}
		else
		{
			if (s.top() == temp)
			{
				v.push_back("-");
				s.pop();
			}
			else
			{
				chk_no = true;
				break;
			}
		}
	}
	if (!chk_no)
	{
		for (int i = 0;i < v.size();i++)
		{
			cout << v[i] << "\n";
		}
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
/*
1. 1에서부터 n까지 순서대로 push를 시키다가 입력된 숫자에 따라 pop을 해줘야 되기 때문에 기존에 스택에 어느정도까지 push를 해주었는지 기억하기 위해 n_state의 변수를 만들었다.

2. 이 스택은 오름차순으로 push를 하기에 입력된 숫자보다 높은 수가 push되어야 한다면 push를 하지않고 pop을 해준다.

3. 2의 과정에서 pop을 시행할때 pop하는 숫자가 입력된 숫자와 다르다면 수열이 안되기 때문에 NO가 출력되고 그 즉시 반복문이 종료된다.

4. 위의 일련된 과정을 거쳐서 시행된 push와 pop의 시행을 전부 벡터 v의 변수에 저장하고 순서대로 출력한다.
*/