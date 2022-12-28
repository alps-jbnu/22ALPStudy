#include<bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

void hannoi(int st, int en, int n) {
    if (n == 1) {
        cout << st << ' ' << en << '\n';
        return;
    }

    hannoi(st, 6 - st - en, n - 1);
    cout << st << ' ' << en << '\n';
    hannoi(6 - st - en, en, n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string s = to_string(pow(2, n)); // long long의 범위는 -2^63 ~ 2^63-1인데 이 문제는 2^100이므로 overflow 문제 발생하므로 다음과 같이 string으로 해결
    int var = s.find('.'); // pow 함수를 통해 double 형이므로(실수)이 문자로 변환할때 소수 점이 저장되므로 다음 식을 통해 소수 점 찾음
    s = s.substr(0, var); // 소수 점 앞자리만 저장하게 한다
    s[s.length() - 1] -= 1; // 2^x - 1이기 때문에 문자의 마지막 index 값에 접근하여 그 값에 -1을 해줌
    cout << s << '\n';

    if (n <= 20) hannoi(1, 3, n);
    return 0;
}