#include <iostream>
using namespace std;

long long int A, B, C;
int cnt = 0;

long long int Solve(int num, int radroot, int per)
{
	if (radroot == 0) return 1;
	if (radroot == 1) return num;
	if (radroot % 2 > 0)
	{
		return Solve(num, radroot - 1, per) * num;
	}

	long long int radical = Solve(num, radroot / 2, per);
	radical %= C;
	return (radical * radical) % C;

}

int main()
{
	cin >> A >> B >> C;

	cout << Solve(A, B, C) % C;

	return 0;
}