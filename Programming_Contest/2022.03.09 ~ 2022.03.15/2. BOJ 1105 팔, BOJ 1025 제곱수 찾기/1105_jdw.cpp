#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string l, r;
    cin >> l >> r;

    int ans = 0;
    int llen = l.length(), rlen = r.length();
    if(llen == rlen)
    {
        for (int i = 0; i < llen; i++)
        {
            if(l[i] == '8' && r[i] == '8')
            {
                ans++;
            }
            if(l[i] != r[i]) break;
        }
    }
    cout << ans;
}