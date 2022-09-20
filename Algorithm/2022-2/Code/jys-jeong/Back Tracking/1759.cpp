#include <bits/stdc++.h>
using namespace std;

char arr[16];
int n, c;
bool vis[16];
vector<char> v;
int mcnt = 0;
int jcnt = 0;
void func(int cur,int st) {
	
	if (cur == 0) {
		if (jcnt >= 2 && mcnt >= 1) {
			for (int i = 0; i < n; i++) {
				cout << v[i];
			}
			cout << '\n';
			return;
		}
		return; 
	}
	for (int i = st; i < c - cur + 1; i++) {
		if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u')	mcnt++;
		else jcnt++;
		v.push_back(arr[i]);
		func(cur - 1, i+1);
		v.pop_back();
		if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u')	mcnt--;
		else jcnt--;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	func(n,0);
	
 }