#include<bits/stdc++.h>
using namespace std;

struct info{
	int index, age;
	string name;
};

bool compare(info a, info b) {
	if (a.age == b.age) return a.index < b.index;
	else return a.age < b.age;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<info> v(n); 
	// 동적할당 이라도 밑에 처럼 입력을 받는다면 벡터의 크기를 명시해줘야 한다.

	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
		v[i].index = i;
	}

	sort(v.begin(), v.end(), compare);

	for (auto i : v) {
		cout << i.age << " " << i.name << "\n";
	}
	return 0;
}

/*
stable_sotr()를 모를 경우 구조체 이용해 해결
*/