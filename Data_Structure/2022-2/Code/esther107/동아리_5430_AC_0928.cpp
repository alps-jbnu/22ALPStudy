#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

bool isreverse;  

deque<int> split(string s, string divid) { 
	
	deque<int> temp;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		temp.push_back(atoi(c)); 
		c = strtok(NULL, divid.c_str());
	}
	return temp;
}


void reverse() { 
	if (isreverse)
	isreverse = false; 

	else 
		isreverse = true; 

}

void pop(deque <int> &q) {

	if (isreverse)
		q.pop_back();

	else
		q.pop_front();
}


int main() {
	int n_testcase; 
	
	string command;
	int size; 
	string array; 

	bool error; 

	cin >> n_testcase;

	while (n_testcase--) {
		deque <int> q; 
		isreverse = false;
		error = false;

		cin >> command;
		cin >> size;
		cin >> array;

		q = split(array, "[],"); 
	

		for (int i = 0; i < command.length(); i++)
		{
			switch (command[i])
			{
				case  'R':
					reverse();
					break;
	
				case 'D':
	
					if (q.empty()) 
					{
						error = true;	
					}
					else
						pop(q); 
					break;
			}

		}


		if (error)
		{
			cout << "error" << '\n';
			continue; 
		}

		cout << '[';
		if (!isreverse) 
		{
			while (q.size())
			{

				cout << q.front();
				q.pop_front();

				if (!q.empty())
					cout << ',';

			}
		}

		else
		{
			while (q.size())
			{
				cout << q.back();
				q.pop_back();

				if (!q.empty())
					cout << ',';
			}
		}

		cout <<']'<<'\n';
	}
}
