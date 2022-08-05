#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
	int n;
	bool errorcheck;
	bool reverse;
	string ps;
	string vs;
	cin>>T;

	for(int i = 0;i<T;++i)
	{
		reverse = false;
		errorcheck = false;
		deque<int> dq;
		string temps;           //입력받은 배열형식의 문자열 'vs' 에서 두 자리 수 이상의 숫자를 파싱할 때 필요              
		cin>>ps >> n >> vs;

		for(int j = 1;j<vs.size();++j)
		{
			if(vs[j] == ',' || vs[j] == ']' && !temps.empty())      //',' 나 ']' 를 만났을 때 임시 문자열에 숫자가 들어있으면 deque에 수 추가
			{
				dq.push_back(stoi(temps));
				temps.clear();      //숫자가 들어있던 임시 문자열 비우기
			}
			else
			{
				temps.push_back(vs[j]);     // 임시문자열에 숫자 추가
			}
		}
		
		for(int j = 0;j<ps.size();++j)
		{
			if(ps[j] == 'R')
			{
				if(reverse)
				{
					reverse = false;
				}
				else
				{
					reverse = true;
				}
			}
			else if(ps[j] == 'D' && dq.empty())
			{
				errorcheck = true;
				break;
			}
			else
			{
				if(reverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		if(errorcheck)
		{
			cout<<"error\n";
		}
		else
		{
			cout<<"[";
			if(reverse)
			{
				for(auto it = dq.rbegin();it!=dq.rend();++it)
				{
					if(it == dq.rend()-1)
					{
						cout<<*it;
					}
					else
					{
						cout<<*it<<",";
					}
				}
			}
			else
			{
				for(auto it = dq.begin();it!=dq.end();++it)
				{
					if(it == dq.end()-1)
					{
						cout<<*it;
					}
					else
					{
						cout<<*it<<",";
					}
				}
			}
			cout<<"]\n";
		}
	}	

}