#include <iostream>
using namespace std;

int N;

void Solve(int i, int j, int num)
{
	if((i / num) % 3 == 1 && (j / num) % 3 == 1)
	{
		cout << ' ';
	}
	else
	{
		if(num / 3 == 0)
		{
			cout << '*';
		}
		else
		{
			Solve(i, j, num / 3);
		}
	}
}

int main() 
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			Solve(i, j, N);
		}
		cout << "\n";
	}
	
	return 0;
}