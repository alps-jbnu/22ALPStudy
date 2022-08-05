#include <bits/stdc++.h>

using namespace std;

int main()
{
    
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<string> v(3, ""), sv(3, "");
    for(int i=0;i<3;i++) cin >> v[i];
    for(int i=0;i<3;i++) cin >> sv[i];
    
    vector<int> check(26, 0);
    for(int i=0;i<3;i++)
    {
        for(char &C : v[i])
        {
            check[C-'A']++;
        }
    }
    int green = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(v[i][j] == sv[i][j])
            {
                green++;
                check[v[i][j]-'A']--;
            }
        }
    }

    int yellow = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(check[sv[i][j]-'A'] > 0 && v[i][j] != sv[i][j])
            {
                yellow++;
                check[sv[i][j]-'A']--;
            }
        }
    }
    cout << green << "\n";
    cout << yellow << "\n";

   return 0;
    
}