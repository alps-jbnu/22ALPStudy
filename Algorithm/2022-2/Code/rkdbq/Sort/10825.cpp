#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class stu {
public:
	string name;
	int kor;
	int math;
	int eng;
};

bool cmp(stu a, stu b) {
	if (a.kor != b.kor) return a.kor > b.kor;
	else {
		if (a.eng != b.eng) return a.eng < b.eng;
		else {
			if (a.math != b.math) return a.math > b.math;
			else return a.name < b.name;
		}
	}
}

int N;
vector<stu> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{}; i < N; i++) {
		stu s;
		cin >> s.name >> s.kor >> s.eng >> s.math;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i{}; i < N; i++) cout << v[i].name << "\n";
	return 0;
}