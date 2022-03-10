#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	list<int> arr;
	for(int i=1 ; i<=n ; i++){
		arr.push_back(i);
	}
	list<int>::iterator iter=arr.begin();
	cout << "<";
	for (; !arr.empty();) {
		for (int i = 0; i < m-1; i++) {
			if (iter == arr.end()) {
				iter = arr.begin();
			}  
			++iter;
		}
		if (iter == arr.end())
			iter = arr.begin();
		cout << *iter;
		if (arr.size() > 1) {
			cout << ", ";
		}
		else {
			cout << ">";
		}
		iter = arr.erase(iter);

	}
}