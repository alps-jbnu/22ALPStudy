#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
int wish[501][501];
bool floyd[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> wish[i][j];
        }
        for (int j = n; wish[i][j] != i; j--)
        {
            wish[i][j] = -1;
        }
    }
    
    memset(floyd, false, sizeof(floyd));
    for (int i = 1; i <= n; i++)
    {
        for (int j : wish[i])
        {
            if(j == -1) continue;
            floyd[i][j] = true;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(floyd[i][k] && floyd[k][j])
                {
                    floyd[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
		for (int j : wish[i])
        {
            if(j == -1) continue;
			if (floyd[j][i])
            {
				cout << j << "\n";
				break;
			}
        }
    }

    return 0;
}