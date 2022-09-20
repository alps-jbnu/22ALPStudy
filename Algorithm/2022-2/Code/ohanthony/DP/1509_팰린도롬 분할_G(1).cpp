#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

char alpha[2505];
bool isPa[2505][2505]; // x에서부터 y까지 Pa 여부에 대한 점화식
int dp[2505]; // st~en의 부분문자열에 존재하는 최소 Pa 수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    string temp = " ";
    temp += s;
    int len = temp.length();

    for(int i = 1; i <= len; i++) {
        alpha[i] = temp[i];
        isPa[i][i] = true; // st==en인 경우 Pa 성림

        // index가 연속해서 같은 숫자일 경우 역시 Pa 성립
        if(i != 1 && alpha[i-1] == alpha[i]) isPa[i-1][i] = true;
    }

    for(int i = 2; i < len; i++){
        for(int j = 1; i + j <= len; j++){
            if(alpha[j] == alpha[j+i] && isPa[j+1][j+i-1]){
                isPa[j][j+i] = true;
            }
        }
    }

    for(int i = 1; i < len; i++){
        for(int j = 1; j <= i; j++){
            if(isPa[j][i]){
                if(dp[i] == 0 || dp[i] > dp[j-1] + 1) dp[i] = dp[j-1] + 1;
            }
        }
    }
    
    cout << dp[len-1];
    return 0;
}

