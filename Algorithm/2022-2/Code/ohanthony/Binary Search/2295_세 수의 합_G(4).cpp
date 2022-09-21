#include <bits/stdc++.h>
using namespace std;

int arr[1005];
vector<int> twoSum;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            twoSum.push_back(arr[i] + arr[j]); // 입력받은 집합에서 먼저 2개의 합을 따로 저장
        }
    }

    sort(twoSum.begin(), twoSum.end());

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(twoSum.begin(), twoSum.end(), arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}