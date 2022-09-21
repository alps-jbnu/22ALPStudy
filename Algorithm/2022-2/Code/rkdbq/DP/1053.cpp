#define MX 51
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str[MX * MX];
int dp[MX][MX];
vector<int> ans;

void swap(char &a, char &b)
{
    char tmp{b};
    b = a;
    a = tmp;
}

void dpInit()
{
    for (int i{}; i < MX; i++)
        for (int j{}; j < MX; j++)
            dp[i][j] = -1;
}

int palindrome(int idx, int st, int en)
{
    int &cur{dp[st][en]};
    if (st >= en)
        return 0;
    if (cur != -1)
        return cur;

    if (str[idx][st] == str[idx][en])
        cur = palindrome(idx, st + 1, en - 1);
    else
    {
        cur = min(palindrome(idx, st, en - 1), palindrome(idx, st + 1, en)) + 1;
        cur = min(cur, palindrome(idx, st + 1, en - 1) + 1);
    }

    return cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str[0];
    int len{(int)str[0].length()};
    for (int i{}; i <= (len * (len - 1) / 2); i++)
        str[i] = str[0];

    int k{1};
    for (int i{}; i < len; i++)
        for (int j{i + 1}; j < len; j++)
        {
            swap(str[k][i], str[k][j]);
            k++;
        }

    for (int i{}; i <= len * (len - 1) / 2; i++)
    {
        dpInit();
        if (i)
            ans.push_back(palindrome(i, 0, len - 1) + 1);
        else
            ans.push_back(palindrome(i, 0, len - 1));
    }
    //for(int i{}; i<ans.size(); i++) cout<<str[i]<<" "<<ans[i]<<"\n";
    cout << *min_element(ans.begin(), ans.end());
    return 0;
}