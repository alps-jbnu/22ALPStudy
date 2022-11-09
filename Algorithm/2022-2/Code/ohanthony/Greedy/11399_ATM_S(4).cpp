#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int atm[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> atm[i];

    sort(atm, atm + n);

    int sum = atm[0];
    int temp = atm[0];
    for (int i = 1; i < n; i++) {
        temp += atm[i];
        sum += temp;
    }
    cout << sum;
    return 0;
}
