#include <iostream>

using namespace std;


long long rec(int a,int b,int c)
{
	if (b == 1) return a % c;
	if (b % 2)
	{
		long long temp = rec(a % c, --b, c);
		return (temp * (a % c)) % c;
	}
	else
	{
		long long temp = rec(a % c, b / 2, c);
		return (temp * temp) % c;
	}
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout<<rec(a, b, c);

	return 0;
}
/*
먼저 고려할 부분을 보았는데, 재귀로 계속 나머지를 연산할 수 있는 방법이 필요했고, 두번째로는 b가 너무 커서 rec함수를 너무 많이 불러내는 것만 유의했다.
1. 먼저 나머지를 연산할 수 있는 방법으로 rec가 불러질때마다 a의 나머지를 반환하도록 하는 방법을 생각했다.

2. b가 너무 커서 rec를 많이 불러내는 것을 방지하기 위해, b의 횟수를 -1씩이 아니라 /2씩 줄어들도록 하면 기존의 시간복잡도보다 log2 n이 줄어든다는 것을 알았고,
b의 횟수를 홀수와 짝수로 나눠서 짝수일때 b/2번째의 나머지값을 제곱해서 나머지연산을 하면 원하는 값이 나왔다. 홀수일땐 b-1번째 나머지 값과 a%c의 나머지값을 곱해서 나머지연산을 취하는 방식으로 진행했다.


*/