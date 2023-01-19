#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<char, int> m;
    char alpha = 'A';
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        m[alpha++] = num;
    }

    stack<double> st;

    for (auto c : s) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            double temp2 = st.top(); st.pop();
            double temp1 = st.top(); st.pop();

            if (c == '+') st.push(temp1 + temp2);
            else if (c == '-') st.push(temp1 - temp2);
            else if (c == '*') st.push(temp1 * temp2);
            else st.push(temp1 / temp2);
        }
        else st.push(m[c]);
    }

    cout << fixed;
    cout.precision(2); // 소수점 자리 고정
    cout << st.top();
    return 0;
}