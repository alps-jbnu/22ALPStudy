#include <iostream>
#include <deque>
using namespace std;

int main() {
	int T;
	cin >> T;

	string cmd;
	int len;
	string val;
	deque<int> vals;
	int error;
	while (T) {
		bool flag = true;
		error = 0;;
		cin >> cmd;
		cin >> len;
		cin >> val;
		int i = 1;
		
		while (val[i] != '\0') {				//숫자들 입력받기... 쉽지 않쿤요
			int x = 0;
			while (val[i] >= '0' && val[i] <= '9') {
				x *= 10;
				x += int(val[i] - '0');
				i++;
			}
			if (x != 0) {
				vals.push_back(x);
			}
			i++;
		}

		for (int i = 0; cmd[i]; i++) {
			if (cmd[i] == 'R') {
				flag = !flag;
			}

			if (cmd[i] == 'D') {
				if (vals.empty()) {
					error++;
					cout << "error\n";
					break;
				}
				if (flag) {
					vals.pop_front();
				}
				else {
					vals.pop_back();
				}
			}

		}
		if (!error) {
			cout << '[';
			for (int i = 0; !vals.empty(); i++) {
				if (flag) {
					cout << vals.front();
					vals.pop_front();
					if (!vals.empty()) {
						cout << ',';
					}
				}
				else {
					cout << vals.back();
					vals.pop_back();
					if (!vals.empty()) {
						cout << ',';
					}
				}

			}
			cout << "]\n";
		}

		T--;
	}


}
