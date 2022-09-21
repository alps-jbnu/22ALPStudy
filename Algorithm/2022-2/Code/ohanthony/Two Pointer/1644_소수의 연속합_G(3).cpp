#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

vector<int> prime;
vector<bool> check;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    check.resize(n + 1, true); // 해당 vector의 값 모두 true로 초기화

    // 에라토스테네스의 체 알고리즘
    /*
    => 해당 수가 소수라면, 해당 수의 배수들은 모두 해당수를 약수로 가지고
       있으므로 소수가 되지 못한다.
    */
    for (int i = 2; i * i <= n; i++) {
        if (!check[i]) continue;
        for (int j = i * i; j <= n; j += i) check[j] = false; // 해당 루프를 돈다는 것은 소수가 아님을 알 수 있다.
        // j가 i의 제곱부터 시작하는 이유는, 그 전의 수는 계산 과정에서 이미 소수 여부가 판별이 되어있기 때문이다.
    }

    for (int i = 2; i <= n; i++) if (check[i]) prime.push_back(i);

    int st = 0, en = 0, count = 0, sum = 0;
    while (1) {
        if (sum >= n) sum -= prime[st++];
        else if (en == prime.size()) break;
        else sum += prime[en++];

        if (sum == n) count++;
    }

    cout << count;
    return 0;
}