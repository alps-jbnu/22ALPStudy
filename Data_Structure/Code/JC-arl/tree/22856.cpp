#include<iostream>

using namespace std;
int N;
int cnt = 0;
int fin;
int lc[1000000];
int rc[1000000];
void inorder(int cur)
{
	if (lc[cur] != 0)	inorder(lc[cur]);
	fin = cur;
	if (rc[cur] != 0)	inorder(rc[cur]);
}
void reinorder(int cur)
{
	int final_cnt;
	//cout << "fin=" << fin;

		
	//cout << "cnt:   " << cnt << "\n";

	if (lc[cur] != 0)
	{
		cnt++;

		reinorder(lc[cur]);
		cnt++;
	}
	//cout <<"cnt:   "<<cnt << "\n";
	//
	//cout << cur<<"\n";
	if (cur == fin)
	{
		cout << cnt;
	}
	if (rc[cur] != 0)
	{
		cnt++;

		reinorder(rc[cur]);

		cnt++;
	}
	//cout << "cnt:   " << cnt << "\n";

	
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p, l, r;
		cin >> p >> l >> r;
		
		if (l != -1)	lc[p] = l;
		if (r != -1)	rc[p] = r;
	}
	inorder(1);

	reinorder(1);

	return 0;
}