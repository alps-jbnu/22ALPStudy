#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

// 이 문제는 기본적으로 범위가 크기 때문에 자료형 long long으로 시작
ll K, N, result;
/*
- K: 이미 가지고 있는 랜선의 개수
- N: 필요한 랜선의 개수
*/

ll length[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++) cin >> length[i];

    sort(length, length + K); // 오름차순으로 정렬

    ll le = 1;
    ll ri = length[K-1]; // 최대 길이 설정

    while (le <= ri) {
        ll mid = (le + ri) / 2;
        ll count = 0; // 자른 랜선의 개수 합

        // 각각의 랜선을 잘랐을때 개수를 합
        for (int i = 0; i < K; i++) count += length[i] / mid;

        if (count >= N) { // 이분탐색으로 접근하므로 count == N이라고 최댓값이라는 보장을 못한다.
            le = mid + 1;
            result = max(result, mid);
        }
        else ri = mid - 1;
    }

    cout << result;
    return 0;
}
