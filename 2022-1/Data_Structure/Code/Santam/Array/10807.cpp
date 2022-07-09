#include <iostream>

using namespace std;

int main()
{
	int num_dic[201] = { 0 };
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		num_dic[temp + 100]++;
	}
	int v;
	cin >> v;
	cout << num_dic[v + 100] << endl;

}