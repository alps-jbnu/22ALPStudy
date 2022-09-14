#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
vector<int> parr;
vector<int> narr;


int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num > 0)
        {
            parr.push_back(num);
        }
        else
        {
            narr.push_back(num);
        }
    }

    sort(parr.begin(), parr.end());
   
    sort(narr.begin(), narr.end());
    reverse(narr.begin(), narr.end());

    while (parr.size() > 1)
    {
        if (*(parr.end() - 1) == 1 || *(parr.end() - 2) == 1)
        {
            ans += (*(parr.end() - 1) + *(parr.end() - 2));
            parr.pop_back();
            parr.pop_back();
        }
        else
        {
            ans = ans + (*(parr.end() - 1) * *(parr.end() - 2));
            parr.pop_back();
            parr.pop_back();
        }
    }
    if (parr.size() != 0)
    {
        if (parr[0] == 1)
        {
            ans++;
        }
        else
        {
            ans += parr[0];
        }
    }

    while (narr.size() > 1)
    {
        ans = ans + (*(narr.end() - 1) * *(narr.end() - 2));
        narr.pop_back();
        narr.pop_back();
    }
    if (narr.size() == 1)
    {
        ans += narr[0];
    }


    cout << ans;
}