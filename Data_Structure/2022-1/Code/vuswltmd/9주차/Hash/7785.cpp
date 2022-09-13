#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
using namespace std;
unordered_set<string> s;
string name_arr[1000000];
int cnt = 0;
int n;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        string in_out;

        cin >> name >> in_out;

        if (in_out == "enter")
        {
            s.insert(name);
        }
        else
        {
            s.erase(name);
        }
    }

    //sort(s.begin(), s.end());
    //reverse(s.begin(), s.end());

    for (auto e : s)
    {
        name_arr[cnt] = e;
        cnt++;
    }

    sort(name_arr, name_arr + cnt);
    reverse(name_arr, name_arr + cnt);

    for (int i = 0; i < cnt; i++)
    {
        cout << name_arr[i];
    }
}