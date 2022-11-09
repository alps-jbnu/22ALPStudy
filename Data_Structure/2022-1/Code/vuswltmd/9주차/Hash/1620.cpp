#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;
unordered_map<string, int> m;
string poketmon[100005];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int mm;
    cin >> mm;

    for (int i = 1; i <= n; i++)
    {
        string name;
        cin >> name;
        poketmon[i] = name;
        m[name] = i;
    }

    for (int i = 0; i < mm; i++)
    {
        string ans;
        cin >> ans;
        bool isnumber = false;

        for (int j = 0; j < ans.size(); j++)
        {
            if (isdigit(ans[j]) == 0)
            {
                isnumber = true;
                break;
            }
        }

        if (isnumber == true) //포켓몬 이름으로 검색
        {
            cout << m[ans] << '\n';
        }
        else //숫자로 검색
        {
            int num = stoi(ans);
            cout << poketmon[num] << '\n';
        }
    }

}