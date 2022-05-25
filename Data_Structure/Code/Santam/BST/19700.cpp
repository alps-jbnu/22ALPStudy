#include <iostream>
#include <set>
#include <map>

using namespace std;

multiset<int> team;
map<int,int, greater<int>> student_h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp_h, temp_k;
		cin >> temp_h >> temp_k;
		student_h.insert(make_pair(temp_h,temp_k));
	}
	for (auto &cnt:student_h)
	{
		int temp = cnt.second - 1;
		auto at = team.lower_bound(temp);
		if (team.empty())
		{
			team.insert(1);
			continue;
		}// team에 요소 없을때 새로운 팀 생성
		if(at==team.end()) //lower_bound는 해당 값보다 같거나 큰값에서 가장 첫번째 요소를 반환하는 건데, 반환값이 teeam.end()면 해당 값보다 큰값이 없다는 것이므로 가장 큰 요소를 지우고 카운트
		{
			int temp2 = *--team.end(); //큰 수에 넣을 수록 가장 팀을 많이 줄일 수 있음-> 키 큰 사람을 수용할 사람은 많지 않기에..
			team.erase(--team.end());
			team.insert(temp2 + 1);
			continue;
		}
		if (at == team.begin()) //찾은 값이 처음 요소일때는 입력했던 값이 가장 작은 경우일 때도 있으므로-> 이 경우에는 어떤 팀을 가더라도 키큰 사람많아서 탈주한다.
		{
			if (temp < *team.begin())
			{
				team.insert(1);
				continue;
			}
		}
		int temp3 = *at; //위의 경우가 아니라면 lower_bound에 해당되는 값을 찾은 것이므로, 해당 위치 값을 삭제하고 그 해당 위치값 +1을 카운트 해서 다시 삽입
		team.erase(at);
		team.insert(temp+1);
	}
	cout << team.size();
	return 0;
}