#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

    string L, R;
    cin >> L >> R;
    if(L.length() != R.length())
    {
        cout << 0;
        return 0;
    }
    int cidx = 0, ans = 0;
    for(size_t i=0;i<L.length();i++)
    {
        if(L[i] != R[i])
        {
            cidx = i;
            break;
        }
        if(L[i] == '8' && R[i] == '8') ans++;
    }
    /*
    int iL = 0, iR = 0;
    for(size_t i=cidx;i<L.length();i++)
    {
        iL += L[i]-'0';
        iL *= 10;
        iR += R[i]-'0';
        iR *= 10;
    }
    iL /= 10;
    iR /= 10;
    */
    cout << ans;
	return 0;
}