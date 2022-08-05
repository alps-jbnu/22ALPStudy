//! 3h
#include <iostream>
#include <string>
#include <cstring>
#include <set>
using namespace std;

char answer[3][3];
char guess[3][3];
int green, yellow;
int x[26];
int y[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 3; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 3; j++)
        {
            answer[i][j] = row[j];
            y[row[j] - 'A']++;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 3; j++)
        {
            if(answer[i][j] == row[j])
            {
                y[row[j] - 'A']--;
                green++;
            }
            else x[row[j] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if(y[i] <= x[i]) yellow += y[i];
        else yellow += x[i]; //! 이거 빼먹음
    }

    cout << green << "\n" << yellow << "\n";
}