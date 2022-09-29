#include <iostream>
#include <algorithm>
using namespace std;

//9251번 
string st1, st2;
int dp[1002][1002];

int main() {
    cin.tie(0);
    ios:: sync_with_stdio(0);

    cin >> st1 >> st2;

    int l1= st1.size();
    int l2= st2.size();
	
    for(int i=1; i<=l2; i++) {
		for (int j = 1; j <= l1; j++) {
			if (st2[i - 1] == st1[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
    }
	cout << dp[l2][l1];
}
