#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int dp[103][103][103]; // i-1, j-1, k-1까지의 LCS값 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            for(int k = 1; k <= len3; k++){
                if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }

    cout << dp[len1][len2][len3];
    return 0;
}