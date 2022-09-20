#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define A pair<string, int> 
#define B pair<int, int>    // 식 길어지는걸 방지하고 가독성으로 위해 #define 선언

bool compare(pair<A, B>& a, pair<A, B>& b)
{
	if (a.X.Y != b.X.Y) {
		return a.X.Y > b.X.Y; // 국어 점수가 감소하는 순서로 내림차순
	}
	else if (a.X.Y == b.X.Y && a.Y.X != b.Y.X) {
		return a.Y.X < b.Y.X; // 국어 점수 같으면 영어 점수 증가하는 순서로 오름차순	
	}
	else if (a.X.Y == b.X.Y && a.Y.X == b.Y.X && a.Y.Y != b.Y.Y) {
		return a.Y.Y > b.Y.Y; // 국어 점수, 영어 점수 같으면 수학 점수가 감소하는 순서로 내림차순
	}
	else return  a.X.X < b.X.X; // 모든 점수가 같으면 사전 순으로 증가하는 순서로
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<A, B>> v;

	for (int i = 0; i < n; i++){
		string name;
		int Korea, Math, English;
		cin >> name >> Korea >> English >> Math;

		v.push_back({ {name, Korea}, {English, Math} });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].X.X << "\n";
	}
	return 0;
}
