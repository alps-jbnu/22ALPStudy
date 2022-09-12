#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
int tem[1000005];
int n;

void merge(int st, int en) {
	int mid = (st + en) / 2;
	int l = st;
	int r = mid;
	for (int i = st; i < en; i++) {
		if (r == en)	tem[i] = arr[l++];
		else if (l == mid)	tem[i] = arr[r++];
		else if (arr[l] <= arr[r])	tem[i] = arr[l++];
		else {
			tem[i] = arr[r++];
		}
	}
	for (int i = st; i < en; i++)	arr[i] = tem[i];
}
void merge_seg(int st, int en) {
	if (en == st + 1)	return;
	int mid = (st + en) / 2;
	merge_seg(st, mid);
	merge_seg(mid , en);
	merge(st, en);

}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_seg(0, n);
	for (int i = 0; i < n; i++)	cout << arr[i]<<'\n';
}
