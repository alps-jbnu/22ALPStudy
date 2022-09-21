#include<bits/stdc++.h>
using namespace std;

int arr[100005]; // 해당 숫자를 사용했는지 판단하는 배열
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string result = "";
	stack<int> s;

	while (n--) {
		int num;
		cin >> num;

		if (s.empty()) { // stack이 비어있는 경우 해당 숫자까지 push
			for (int i = 1; i <= num; i++) {
				if (arr[i] == 0) {
					s.push(i);
					result += "+\n";
					arr[i]++; // 해당 숫자가 사용되었으면 0이 아닌 1의 값
				}
			}
			s.pop();
			result += "-\n";
		}
		else {
			// stack의 top()과 해당 숫자가 같으면 pop
			if (!s.empty() && s.top() == num) { 
				s.pop();
				result += "-\n";
			}
			else if (!s.empty() && s.top() < num) {
				for (int i = s.top() + 1; i <= num; i++) {
					if (arr[i] == 0) {
						s.push(i);
						result += "+\n";
						arr[i]++;
					}
				}
				s.pop();
				result += "-\n";
			}
			else if (!s.empty() && s.top() > num) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << result;
	return 0;
} 