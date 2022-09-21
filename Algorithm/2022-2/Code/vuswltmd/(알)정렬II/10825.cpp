#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;



class Student
{
public: string name;
	  int kor;
	  int eng;
	  int math;
};

bool cmp(const Student a, const Student b)
{
	if (a.kor > b.kor)
	{
		return true;
	}
	else if (a.kor < b.kor)
	{
		return false;
	}
	else
	{
		if (a.eng < b.eng)
		{
			return true;
		}
		else if (a.eng > b.eng)
		{
			return false;
		}
		else
		{
			if (a.math > b.math)
			{
				return true;
			}
			else if (a.math < b.math)
			{
				return false;
			}
			else
			{
				if (a.name < b.name)
				{
					return true;
				}
				else if (a.name >= b.name)
				{
					return false;
				}
			}
		}
	}
}

vector<Student> student;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string st;
		int kor;
		int eng;
		int math;

		Student m;
		cin >> m.name >> m.kor >> m.eng >> m.math;

		student.push_back(m);
	}

	sort(student.begin(), student.end(), cmp);

	for (int i = 0; i < student.size(); i++)
	{
		cout << student[i].name << '\n';
	}
}