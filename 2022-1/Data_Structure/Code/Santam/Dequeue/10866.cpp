#include <iostream>

using namespace std;

int deque_arr[20001] = { 0 };

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int n;
	cin >> n;

	int front_pos = 10000;
	int back_pos = 10001;
	int size = 0;

	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push_front")
		{
			int push_num;
			cin >> push_num;
			deque_arr[front_pos] = push_num;
			size++;
			front_pos--;
		}
		if (temp == "push_back")
		{
			int push_num;
			cin >> push_num;
			deque_arr[back_pos] = push_num;
			size++;
			back_pos++;
		}
		if (temp == "pop_front")
		{
			if (size)
			{
				cout << deque_arr[front_pos+1] << "\n";
				size--;
				front_pos++;
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		if (temp == "pop_back")
		{
			if (size)
			{
				cout << deque_arr[back_pos-1] << "\n";
				size--;
				back_pos--;
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		if (temp == "size")
		{
			cout << size << "\n";
		}
		if (temp == "empty")
		{
			if (size) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		if (temp == "front")
		{
			if (size) cout << deque_arr[front_pos+1] << "\n";
			else cout << -1 << "\n";
		}
		if (temp == "back")
		{
			if (size) cout << deque_arr[back_pos - 1] << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}

/*
1. 덱을 보면 큐의 기능에서 push와 pop의 기능을 양방향이 되도록 추가한거랑 같다고 생각이들었다.

2. 따라서 큐의 기능에 front에 push와 pop을 추가했고 그와 동시에 front_pos,back_pos가 배열의 중심이 되도록했다.
==> 덱은 양방향에서 push,pop이 일어나서 초기 시작점이 중감 지점일 필요가 있었다.
*/