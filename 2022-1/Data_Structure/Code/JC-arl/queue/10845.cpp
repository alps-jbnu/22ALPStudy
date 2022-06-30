#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(void)
{
	int n,menu;
	cin >> n;
	cin.ignore();
	queue<int> qu;
	for (int k = 0; k < n; k++)
	{
		string s;
		int num;
		cin>>s;
		
		if (s == "push")		//push
		{
			cin >> num;
			qu.push(num);
		}
		else if (s == "pop")	//pop
		{
			if (qu.empty())
				cout << -1 << endl;
			else
			{
				cout << qu.front() << endl;
				qu.pop();
			}
		}
		else if (s == "size")	//size
		{
			cout << qu.size() << endl;
		}
		else if (s == "empty")	//empty
		{
			if (qu.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (s == "front")	//front
		{
			if (qu.empty())
				cout << -1 << endl;
			else
				cout << qu.front() << endl;
		}
		else if (s == "back")	//back
		{
			if (qu.empty())
				cout << -1 << endl;
			else
				cout << qu.back() << endl;
		}


	}


	return 0;
}
//string s;
//getline(cin, s);
//
//if (s.find("push") == 0)		//push
//{
//	qu.push(s[s.length()-1]-'0');
//}
//else if (s.find("pop") == 0)	//pop
//{
//	if (qu.empty())
//		cout << -1 << endl;
//	else
//	{
//		cout << qu.front() << endl;
//		qu.pop();
//	}
//}
//else if (s.find("size") == 0)	//size
//{
//	cout << qu.size() << endl;
//}
//else if (s.find("empty") == 0)	//empty
//{
//	if (qu.empty())
//		cout << 1 << endl;
//	else
//		cout << 0 << endl;
//}
//else if (s.find("front") == 0)	//front
//{
//	if (qu.empty())
//		cout << -1 << endl;
//	else
//		cout << qu.front() << endl;
//}
//else if (s.find("back") == 0)	//back
//{
//	if (qu.empty())
//		cout << -1 << endl;
//	else
//		cout << qu.back() << endl;
//}