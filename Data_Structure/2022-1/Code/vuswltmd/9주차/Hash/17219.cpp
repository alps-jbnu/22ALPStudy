#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<string, string> mp;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string site, PW;
        cin >> site >> PW;

        mp[site] = PW;
    }

    for (int i = 0; i < m; i++)
    {
        string site;
        cin >> site;

        cout << mp[site] << '\n';
    }
}