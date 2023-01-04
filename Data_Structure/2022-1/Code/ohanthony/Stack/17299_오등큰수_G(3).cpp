#include<bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int arr[1000005];
int temp[1000005];
int result[1000005];
stack<pair<int, int>> s;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[arr[i]]++; // 해당 숫자가 나오는걸 카운트 해주는 처리 코드
    }

    for (int i = 0; i < n; i++) v.push_back({ arr[i], temp[arr[i]] }); // vector<pair<int, int>>로 접근


    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().Y <= v[i].Y) s.pop();

        if (s.empty()) result[i] = -1;
        else result[i] = s.top().X;

        s.push({ v[i].X, v[i].Y });
    }

    for (int i = 0; i < n; i++) cout << result[i] << ' ';
    return 0;
}