#include <bits/stdc++.h>
using namespace std;

string s;
int d[52][52];
int dp(int st, int en) {
    if (st >= en) return 0;
    if (d[st][en] != -1)  return d[st][en];
    d[st][en]=INT_MAX;
    d[st][en] = min({dp(st + 1,en) + 1,dp(st,en - 1) + 1,dp(st + 1, en - 1)+(s[st]!=s[en]) });
    return d[st][en];
    
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int ans = INT_MAX;
    memset(d, -1, sizeof(d));
    ans = dp(0, s.length() - 1);
    for (int i = 0; i < s.length(); i++) {
        for (int j = i+1; j < s.length(); j++) {
            memset(d, -1, sizeof(d));
            swap(s[i], s[j]);
            ans = min(ans, dp(0, s.length()-1)+1);
            swap(s[i], s[j]);
        }
    }
    cout << ans;
}

// 점화식 세우는게 어려움
/*     A C A Y K P
*    C 0 1 1 1 1 1
     A 1 1 2 2 2 2
     P 1 1 2 2 2 3
     C 1 2 2 2 2 3
     A 1 2 3 3 3 3
     K 1 2 3 3 4 4    if(s1[i]==s2[j]) d[i][j]=d[i-1][j-1]+1;
                      else d[i][j]=max(d[i-1][j],d[i][j-1]);
*/
