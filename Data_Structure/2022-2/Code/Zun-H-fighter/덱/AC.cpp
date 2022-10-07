#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

char ch1[1000001];

int main() {
	int T, end;
	string str1, str2;
	cin >> T;
	for (int i = 0; i < T; i++) {
		bool plag = false, plag2 = true;
		deque<int> D;
		cin >> str1 >> end >> str2;
		strcpy(ch1, str2.c_str());
		char* tmp = strtok(ch1, "[,]");
		while (tmp) {
			D.push_front(stoi(tmp));
			tmp = strtok(NULL, "[,]");
		}
		for (int j = 0; j < str1.size(); j++) {
			if (str1[j] == 'R') {
				plag = plag ? false : true;
			}
			else if (str1[j] == 'D') {
				if (D.empty()) {
					cout << "error\n";
					plag2 = false;
					break;
				}
				else if (plag) {
					D.pop_front();
				}
				else
					D.pop_back();
			}
		}
		if (plag2 == true) {
			deque<int>::iterator iter;
			if(plag){
				cout << "[";
				for (iter = D.begin(); iter != D.end(); iter++) {
					cout << *iter;
					if (iter != D.end()-1)
						cout << ",";
				}
				cout << "]\n";
			}
			else {
				cout << "[";
				deque<int>::reverse_iterator riter(D.rbegin());
				for (; riter != D.rend(); riter++) {
					cout << *riter;
					if (riter != D.rend() - 1)
						cout << ",";
				}
				cout << "]\n";
			}
		}
	}
	return 0;
}
