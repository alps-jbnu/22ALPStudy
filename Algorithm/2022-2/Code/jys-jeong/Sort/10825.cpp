#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int korea;
	int math;
	int english;
	string name;
}student;


bool compare(student a, student b) {
	if (a.korea == b.korea&&a.english==b.english&&a.math == b.math)	return a.name < b.name;
	else if (a.korea == b.korea&& a.english == b.english)	return a.math > b.math;
	else if (a.korea == b.korea)	return a.english< b.english;
	return a.korea > b.korea;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<student> vec(n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		string s;
		cin >> vec[i].name >> vec[i].korea >> vec[i].english >> vec[i].math;
		
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].name << '\n';
	}
}
