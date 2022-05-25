#include <bits/stdc++.h>
using namespace std;

string Bar = "____";

void func(int n, int c) {
	string undBar = "";
	int val = c - n;
	while (val--) //0에 가까워질 수록 _가 많아짐
		undBar += Bar;
	cout << undBar << "\"재귀함수가 뭔가요?\"\n";

	if (n == 0) {
		cout << undBar << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		cout << undBar << "라고 답변하였지.\n";
		return;
	}

	cout << undBar << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	cout << undBar << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	cout << undBar << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

	func(n - 1, c);
	cout << undBar << "라고 답변하였지.\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	func(n,n);
}