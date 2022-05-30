#include<iostream>
#include<vector>

using namespace std;
int N;
int lc[30];
int rc[30];
void preorder(int cur)
{
	cout << char(cur + 'A');
	if (lc[cur] != 0)	preorder(lc[cur]);
	if (rc[cur] != 0)	preorder(rc[cur]);
}

void inorder(int cur)
{
	if (lc[cur] != 0)	inorder(lc[cur]);
	cout << char(cur + 'A');
	if (rc[cur] != 0)	inorder(rc[cur]);
}

void postorder(int cur)
{
	if (lc[cur] != 0)	postorder(lc[cur]);
	if (rc[cur] != 0)	postorder(rc[cur]);
	cout << char(cur + 'A');
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.')	lc[p - 'A'] = l - 'A';
		if (r != '.')	rc[p - 'A'] = r - 'A';
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	return 0;
}