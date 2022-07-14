#include <iostream>

using namespace std;

int que_arr[10001] = { 0 };

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int size = 0;
	int front_pos = 1;
	int back_pos = 1;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int temp_int;
			cin >> temp_int;
			back_pos = front_pos + size;
			size++;
			que_arr[back_pos] = temp_int;
		}
		if (temp == "pop")
		{
			if (size)
			{
				cout << que_arr[front_pos] << "\n";
				front_pos++;
				size--;
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
			if (size) cout << que_arr[front_pos] << "\n";
			else cout << -1 << "\n";
		}
		if (temp == "back")
		{
			if (size) cout << que_arr[back_pos] << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;
}

/*
1. 큐의 개념과 각가의 기능에 대해 알고 구현하는 문제라고 판단, 큐는 먼저 들어온 것이 먼저 나가는 방식이라는 것을 확인

2. 큐의 막대가 될 배열 하나를 지정해주었고, size,front_position,back_position을 알기위한 변수를 설정해주었다.

3. push에서는 입력된 값에 대해 푸쉬하면서 back_pos의 값을 front값과 size값의 합으로 설정하고 그 위치에 입력된 값을 저장

4. pop에서는 front부분에서 부터 빠져야되므로 pop으로 해당 위치를 빼주면서 front값을 하나씩 늘려주었다.

5. 나머지 기능들은 2에서 만든 변수를 활용해 적절히 구현했다.
*/