#include <iostream>
#include <vector>

using namespace std;

int res,tree_n,erase_n;;
int p[51] = { 0 };
vector<int> leaf;

int Search_Leaf(int search_n,int size,int option)
{
	if (search_n == -1) return 0; // 루트가 사라지면 리프가 생성되지 않음
	for (int i = 0;i < size;i++)
	{
		if (i == option) continue;
		if (p[i] == search_n) return 0;
	}
	return 1;
}

void Erase(int n)
{
	for (int i=0 ;i<leaf.size();i++)
	{
		int cnt = leaf[i];
		if (cnt == n)
		{
			res--;
			if (Search_Leaf(p[n], tree_n, n)) res++; //리프가 사라질때 그 부모가 리프인지 확인할 필요있음
			continue;
		}
		while (cnt!=-1)
		{
			if (p[cnt] == n)
			{
				res--;
				if (Search_Leaf(p[n], tree_n, n)) res++;
				break;
			}
			cnt = p[cnt];
		}
	}
}

int main()
{
	cin >> tree_n;
	for (int i = 0;i < tree_n;i++) cin >> p[i];
	cin >> erase_n;
	for (int i = 0;i < tree_n;i++)
	{
		if (Search_Leaf(i,tree_n,-1)) leaf.push_back(i);
	}
	res = leaf.size();
	Erase(erase_n);
	cout << res;
}