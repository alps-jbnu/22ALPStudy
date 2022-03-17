#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	stack<int> st;
	queue<char> qu;
	int num, count = 0;
	cin >> num;
	for (int i = 1; i <= n; i++)
	{
		st.push(i);
		qu.push('+');
		while (1)
		{
			if (st.empty())
				break;
			if (st.top() == num)
			{

				st.pop();
				qu.push('-');
				if (count == n - 1)
					break;
				scanf("%d", &num);		//받은값
				count++;
			}
			else
			{
				break;
			}

		}
	}if (!st.empty())
		cout << "NO";
	else
		while (!qu.empty())
		{
			printf("%c\n", qu.front());
			//cout << qu.front()<<endl;
			qu.pop();
		}




	return 0;
}
//1234-num== =>pop
/*입력은 1~n까지 하나씩 순서대로(*중복x
* 출력은 입력된 수열을 만들기 위한 연산 출력
* + - push
* - - pop
*
*  push는 1부터 오름차순 입력
*
* 풀이 -
*/
