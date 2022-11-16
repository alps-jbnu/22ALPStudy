#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int dp[1005][1005]; // i-1, j-1까지의 LCS값 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int len_s1 = s1.length();
    int len_s2 = s2.length();

    for(int i = 1; i <= len_s1; i++){
        for(int j = 1; j <= len_s2; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[len_s1][len_s2];
    return 0;
}

/*
1. 최대 1000글자로 이루어진 문자열이므로 이중 for문 이용하면 시간복잡도는 10^6이 나오게 된다.

2. 예시의 두 문자열을 비교하면 다음과 같은 식이 나오게 된다.
  A C A Y K P
--------------
C 0 1 1 1 1 1 
A 1 1 2 2 2 2 
P 1 1 2 2 2 3
C 1 2 2 2 2 2
A 1 2 3 3 3 3 
K 1 2 3 3 4 4

=> 숫자가 변화하는 지점이 크게 2가지 있다.
case 1.
  예를들어 ACA CA 지점에서 dp 값이 증가 되었는데 이 지점에서는 두 문자열의 같을때 일어났음으로 점화식 dp[i][j] = dp[i-1]dp[j-1] + 1이 도출된다.

case 2.
  예를들어 ACA CAP 지점을 보면 마찬가지로 dp 값이 증가했는데 이는 두 문자열이 다를때 일어난 경우이다.
  여기서는 점화식 dp[i-1][j]와 dp[i][j-1] 값 중에서 최대값을 취해야 한다. 
*/