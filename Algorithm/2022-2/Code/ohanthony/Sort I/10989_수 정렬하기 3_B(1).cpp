#include<bits/stdc++.h>
using namespace std;

int arr[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++; // arr 위치에 해당하는 배열 값을 증가시킨다
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) { // arr의 값이 0이 아니면 고려대상이 아니다
			for (int j = 0; j < arr[i]; j++) {
				cout << i << "\n";
				// 배열 요소의 값만큼 배열의 인덱스 값을 출력하여 해결한다.
			}
		}
	}
	return 0;
}

/*
수의 개수가 10,000,000이기 때문에 
*/