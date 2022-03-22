#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

const int MX = 1000005;
int unused = 1;
int pre[MX], nxt[MX];
char dat[MX];

void insert(int addr, char c) {
	dat[unused] = c;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;

}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if(nxt[addr]!=-1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	string s;
	cin >> s;
	int cursor = 0;
	for (auto c : s) {
		insert(cursor, c);
		cursor++;
	}

	int m;
	cin >> m;
	char cmd;
	while (m--) {
		cin >> cmd;
		if (cmd == 'P') {
			char c;
			cin >> c;
			insert(cursor, c);
			cursor = nxt[cursor];
		}
		if (cmd == 'L') {
			if (pre[cursor] != -1) {
				cursor = pre[cursor];
			}
		}
		if (cmd == 'D') {
			if (nxt[cursor] != -1) {
				cursor = nxt[cursor];
			}
		}
		if (cmd == 'B') {
			if (cursor != 0) {
				erase(cursor);
				cursor = pre[cursor];
			}
		}
	}
	traverse();
}
