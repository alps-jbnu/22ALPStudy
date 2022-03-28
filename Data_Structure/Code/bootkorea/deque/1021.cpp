#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {

	int N, M, num, result = 0;
	deque<int>dq;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {

		cin >> num;
		int count = 0;
		while (num != dq.front())
		{
			dq.push_back(dq.front());
			dq.pop_front();
			count++;
		}
		result += min(count, int(dq.size() - count));
		dq.pop_front();

	}

	cout << result << "\n";

	return 0;
}