#include <iostream>

using namespace std;

char string_data[1000001];
int pre[1000001];
int nxt[1000001];

int main()
{	
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int data_end = 0;
		int length = 0;
		int cusor = 0;
		fill(pre, pre + 1000000, -1);
		fill(nxt, nxt + 1000000, -1);
		string temp;
		cin >> temp;
		for (int j = 0;j < temp.length();j++)
		{
			switch (temp[j])
			{
			case'-':
				if (pre[cusor] != -1)
				{
					nxt[pre[cusor]] = nxt[cusor];
					if (nxt[cusor] != -1) pre[nxt[cusor]] = pre[cusor];
					cusor = pre[cusor];
					length--;
				}
				break;
			case'<':
				if (pre[cusor] != -1)
				{
					cusor = pre[cusor];
				}
				break;
			case'>':
				if (nxt[cusor] != -1)
				{
					cusor = nxt[cusor];
				}
				break;
			default:
				data_end++;
				string_data[data_end] = temp[j];
				pre[data_end] = cusor;
				nxt[data_end] = nxt[cusor];
				nxt[cusor] = data_end;
				if(nxt[data_end]!=-1)pre[nxt[data_end]] = data_end;
				cusor = nxt[cusor];
				length++;
				break;
			}
		}
		int at = nxt[0];
		for (int j = 0;j < length;j++)
		{
			cout << string_data[at];
			at = nxt[at];
		}
		cout << "\n";
	}

	return 0;
}