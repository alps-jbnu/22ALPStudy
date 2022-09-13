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

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    int temp = 0;
    int sign = 1;

    string equ;
    cin >> equ;

    for (char c : equ)
    {
        if (c == '-' || c == '+')
        {
            ans = ans + (temp * sign);

            cout << ans << endl;
            if (c == '-')
            {
                sign = -1;
            }
            temp = 0;
        }
        else
        {
            temp = temp * 10;
            temp += c - '0';
        }
    }

    ans = ans + (temp * sign);
    cout << ans;
}