#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp,num_temp;
		int size,cnt=0,str_at = 0;;
		cin >> temp >> size >> num_temp;
		deque<string> d;
		bool chk_R = false , chk_error=false;

		num_temp.erase(num_temp.begin());
		num_temp.erase(num_temp.end()-1);

		while (cnt<size)
		{
			string temp_string="";
			while (num_temp[str_at] != ',')
			{
				if (str_at >= num_temp.size()) break;
				temp_string.push_back(num_temp[str_at]);
				str_at++;
			}
			d.push_back(temp_string);
			str_at++;
			cnt++;
		}
		while (temp.size() > 0)
		{
			if(temp.front()=='R')
			{
				chk_R = !chk_R;
			}
			if (temp.front() == 'D')
			{
				if (d.size())
				{
					if (chk_R) d.pop_back();
					else d.pop_front();
				}
				else
				{
					cout << "error" << "\n";
					chk_error = true;
					break;
				}
			}
			temp.erase(temp.begin());
		}

		if (!chk_error)
		{
			cout << "[";
			int d_length = d.size();
			for (int j = 1;j < d_length;j++)
			{
				if (chk_R)
				{
					cout << d.back() << ",";
					d.pop_back();
				}
				else
				{
					cout << d.front() << ",";
					d.pop_front();
				}
			}
			if(d_length) cout << d.back() << "]\n";
			else cout << "]\n";
		}
	}
	return 0;
}
/*
1.먼저 배열의 수를 뒤집어 빼거나 안뒤집고 뺄수도 있기에 양방향에서 배열의 수의 제거가 일어나기에 덱을 사용했다.

2.이 문제에서는 배열에 있는 수를 수의 형태만으로 준것이 아닌 특정 기호가 포함된 문자열로 입력이 되어 분류를 해줘야 한다.

3.입력된 배열 문자열을 분류할때 []기호는 미리 없애준 후에 ,를 기준으로 나눠서 각 숫자를 덱에 넣어주었다.

4.R과 D의 함수에서 R의 명령횟수가 짝수인지 홀수인지 중요하기에 체크 변수를 만들고 그 변수에 따라 D의 명령에서 pop을 하는 위치를 지정

5.모든 명령이 끝나고 형식에 맞게 덱에 있는 수를 출력해주었다.
*/