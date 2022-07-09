#include<bits/stdc++.h>
using namespace std;


bool desc(int a, int b) {
	return a > b;
}


int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		multiset<int> mul;
		for (int j = 0; j < num; j++) {
			char oper;
			int number;
			cin >> oper >> number;
			if (oper == 'I') {
				mul.insert(number);
			}
			else if (!mul.empty()) {
				if (oper == 'D') {
					if (number == 1) {
						auto it = mul.end();
						--it;
						mul.erase(it);
					}
					else if (number == -1) {
						mul.erase(mul.begin());
					}
				}
			}
		}
		if (!mul.empty()) {
			auto iter = mul.end();
			--iter;
			auto iter1 = mul.begin();
			cout <<*iter << " " << *iter1<<"\n";
		}
		else {
			cout << "EMPTY\n";
		}
	}
}