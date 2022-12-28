#include <iostream>
using namespace std;

int i = 0;

void Line(int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
		cout << "____";
}

int RecursiveFunc(int repeat)
{
	i++;
	if (repeat >= 1) {
		Line(i);
		cout << "\"재귀함수가 뭔가요?\"\n";
		Line(i);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		Line(i);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		Line(i);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		RecursiveFunc(repeat - 1);
		i--;
		Line(i);
		cout << "라고 답변하였지.\n";
	}

	else {
		Line(i);
		cout << "\"재귀함수가 뭔가요?\"\n";
		Line(i);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		Line(i);
		cout << "라고 답변하였지.\n";

		return 0;
	}

}



int main(void)
{
	int repeat = 0;
	cin >> repeat;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	RecursiveFunc(repeat);
	return 0;
}
