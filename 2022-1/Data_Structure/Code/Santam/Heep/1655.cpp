#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> lower_n;
	priority_queue<int, vector<int>, greater<int>> upper_n;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (lower_n.empty() || lower_n.top() > t) lower_n.push(t); //lower가 빈경우엔 그냥 넣어주면 되고, 그게 아니면 비교해서 t가 작으면 넣어준다.
		else upper_n.push(t); // 위의 경우가 아니면, t가 lower의 top보다 크거나 같으므로 upper에 넣는다.
		int op = lower_n.size() - upper_n.size();
		switch (op)
		{
		case 2:
			upper_n.push(lower_n.top());
			lower_n.pop();
			cout << lower_n.top() << "\n";
			break;
		case -2: 
			lower_n.push(upper_n.top());
			upper_n.pop();
			cout << lower_n.top() << "\n"; // lower랑 upper는 위의 코드를 실행하면 사이즈가 같아지므로 무조건 작은 값인 lower출력
			break;
		case -1:
			cout << upper_n.top() << "\n";
			break;
		default: //case가 1인 경우도 있지만 0인 경우에도 작은 값을 꺼내야 되므로 default로 통합
			cout << lower_n.top() << "\n";
			break;
		}
	}
	return 0;
}

/*
이 문제의 아이디어로 최소힙과 최대힙을 만들어서 값을 넣을때마다 항상 두힙중에 하나는 가운데값을 가지게 하는 걸 생각했다.
1. 처음에 받는 t값은 일단 lower에 넣어주고 그 다음부터는 lower의 top과 비교해준다.
2. lower의 top보다 작은건 lower에, 그렇지 않으면 upper에 넣어준다.
3. 가운데 값을 항상 표현하기 위해서 lower와 upper의 사이즈차이가 2이상나면 생각과 어긋나기때문에 사이즈가 큰 힙에서 작은쪽으로 top의 원소를 이동시킨다.
4. 1~3을 반복하는데 반복할때마다 값을 출력해준다. 만약 사이즈 차이가 2이상이면 사이즈를 같게 만들고 lower.top출력 1정도 차이나면 큰 힙의 top을 출력, 같으면 lower.top을 출력한다.
*/