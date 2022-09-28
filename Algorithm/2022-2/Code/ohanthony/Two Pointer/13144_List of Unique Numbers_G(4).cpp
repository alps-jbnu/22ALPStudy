#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int arr[100005];
bool vis[100005]; // 중복된 수 있는지 여부 판단

ll n, result, en;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int st = 0; st < n; st++) {
        while (en < n) {
            if (vis[arr[en]]) break; // 중복된 수가 있을 경우 빠져나감
            vis[arr[en]] = true; // 중복된 수 체크
            en++;
        }

        result += en - st;
        vis[arr[st]] = false;
    }

    cout << result;
    return 0;
}
