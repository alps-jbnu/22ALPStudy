#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int d[1005][1005];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for (int i = 1; i < s1.length() + 1; i++) {
        for (int j = 1; j < s2.length() + 1; j++) {
            if (s1[i - 1] == s2[j - 1])    d[i][j] = d[i - 1][j - 1] + 1; //해당 행에서 서로 같은 문자를 찾게 되면 이전의 가장 긴 부분 수열 길이에 1을 더해 저장
            else
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);  // 같은 문자가 아닐 때 이전의 가장 긴 부분 수열 길이를 가져온다
            }
        }
    }
    int i = s1.length();
    int j = s2.length();
    string s="";
    while (i != 0 && j != 0) {
        if (d[i][j] == d[i - 1][j])  --i;
        else if (d[i][j] == d[i][j - 1]) --j;
        else {
            --i;
            --j;
            s += s1[i];
        }
    }
    

    cout << d[s1.length()][s2.length()] << '\n';
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }

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

