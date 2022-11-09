#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k; int l;
    cin >> k >> l;

    
    for (int i = 0; i < l; i++)
    {
        string student_num;
        cin >> student_num;

        if (mp.find(student_num) != mp.end())
        {
            mp.erase(student_num);
            mp[student_num] = i;
        }
        else
        {
            mp[student_num] = i;
        }
    }

    vector<pair<string, int >> V(mp.begin(), mp.end());

    sort(V.begin(), V.end(), cmp);

    int en = min(k, (int)V.size());

    for (int i = 0; i < en; i++)
    {
        cout << V[i].first << '\n';
    }

}