#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void fight(int& a, int &b, vector<int>& A, vector<int>& B)
{
	int acnt = 0, bcnt = 0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(A[i] > B[j]) acnt++;
			else if(A[i] < B[j]) bcnt++;
		}
	}
	if(acnt > bcnt)
	{
		a++;
		b--;
	}
	else if(bcnt > acnt)
	{
		b++;
		a--;
	}
}

void solve()
{
	vector<int> A(4, 0), B(4, 0), C(4, 0);
	for(int i=0;i<4;i++) cin >> A[i];
	for(int i=0;i<4;i++) cin >> B[i];

	for(int i=1;i<=10;i++)
	{
		C[0] = i;
		for(int j=1;j<=10;j++)
		{
			C[1] = j;
			for(int k=1;k<=10;k++)
			{
				C[2] = k;
				for(int l=1;l<=10;l++)
				{
					C[3] = l;
					int a = 0, b = 0, c = 0;
					fight(a, b, A, B);
					fight(b, c, B, C);
					fight(a, c, A, C);
					if(a == 0 && b == 0 && c == 0)
					{
						cout << "yes" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "no" << endl;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--)
	{
		solve();
	}

	return 0;
}