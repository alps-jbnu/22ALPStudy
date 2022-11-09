#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1) {
        int n;
        cin >> n; // 직사각형의 수
        if(n == 0) break;

        ll result = 0; // 결과값
        stack<ll> s;   // 이전 위치의와 개수를 저장하기 위해 stack 사용
        ll height[100005] = {0, };
        for(int i = 1; i <= n; i++) cin >> height[i];
        s.push(0);

        for(int i = 1; i <= n+1; i++){ // n+1까지 해야 맨 마지막에 쌓인 코드들을 계산하지 않고 종료하기 때문이다.
            while(!s.empty() && height[s.top()] > height[i]){
                ll temp = s.top();
                s.pop();

                ll area = height[temp]*(i-s.top()-1);
                result = max(result, area);
            }
            s.push(i);
        }
        cout << result << "\n";
    }
    return 0;
}
