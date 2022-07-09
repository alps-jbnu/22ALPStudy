#include <iostream>

using namespace std;

int main()
{
	int stack[10001] = { 0 };
	int pos = 0;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int num;
			cin >> num;
			stack[pos++] = num;
		}
		if (temp == "pop")
		{
			if (pos != 0)
			{
				pos--;
				cout << stack[pos] << endl;
			}
			else cout << -1 << endl;
		}
		if (temp == "top")
		{
			if (pos != 0)
			{
				cout << stack[pos-1] << endl;
			}
			else cout << -1 << endl;
		}
		if (temp == "size")
		{
			cout << pos << endl;
		}
		if (temp == "empty")
		{
			if (!pos) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}

	return 0;
}