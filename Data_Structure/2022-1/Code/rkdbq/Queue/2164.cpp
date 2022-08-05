#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> cardDeck;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		cardDeck.push(i);
	}
	while (cardDeck.size() != 1) {
		cardDeck.pop();
		cardDeck.push(cardDeck.front());
		cardDeck.pop();
	}
	cout << cardDeck.front();
}