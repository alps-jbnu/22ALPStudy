#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, L;
deque<pair<int, int>> dCandidate;
vector<int> A, D;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i{}; i < N; i++)
	{
		int input;
		cin >> input;
		A.push_back(input);
	}
	for (int i{}; i < N; i++)
	{
		while (dCandidate.size() != 0 && dCandidate.back().first > A[i])
		{
			dCandidate.pop_back();
		}
		dCandidate.push_back(make_pair(A[i], i));
		while (dCandidate.size() != 0 && dCandidate.back().second - dCandidate.front().second >= L)
		{
			dCandidate.pop_front();
		}
		D.push_back(dCandidate.front().first);
	}
	for (int i{}; i < D.size(); i++)
	{
		cout << D[i] << " ";
	}

	return 0;
}