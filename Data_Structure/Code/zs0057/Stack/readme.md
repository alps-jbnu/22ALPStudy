# [탑](https://www.acmicpc.net/problem/2493)

**문제 설명**

높이가 서로 다른 탑 들이 왼쪽으로 신호를 보냈을 때 자기보다 높이가 큰 탑이 있다면 그 탑의 장소(인덱스)를 반환하는 문제

**발상**  

임의로 주어지는 수 중에서 전 값이 자기보다 큰지 작은지를 판단해야한다? -> 스택

**조건분석**
1. 서로 다른 높이의 탑 -> 주어지는 탑들의 높이는 모두다 다르다.
2. 주어지는 탑의 개수는 500,000개다. -> 시간복잡도는 O(N^2)가 되면 안된다.
3. 높이는 100,000,000 이하의 정수다. -> int 사용 가능 (int의 최대값은 2,147,483,647)

--------------

### 첫번째 코드
```cpp
#include <bits/stdc++.h>

using namespace std;
vector<long> top;
long arr[500001];

int main(void) {
	long n;
	cin >> n;
	vector<long>::iterator iter;
	for (int i = 0; i < n; i++) {
		long a;
		cin >> a;
		top.push_back(a);
	}
	stack<int> st;

	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() < top[i]) {
			st.pop();
		}

		if (st.empty()) {
			arr[i] = 0;
		}
		else {
			iter = find(top.begin(), top.end(), st.top());
			arr[i] = distance(top.begin(), iter) + 1;
		}
		st.push(top[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
```

**문제점**

인덱스 찾으려 할 때 사용하는 find함수의 시간복잡도는 O(N)이므로 총 시간복잡도가 O(N^2)이 됨. 그러므로 시간초과가 발생함.
 
**해결 방안**

find함수를 사용하는 대신에 stack에 있는 pair를 사용하여 스택안에 index와 탑의 높이를 같이 받음
 
### 두번째 코드
 #include <bits/stdc++.h>

```cpp
using namespace std;
stack<pair<int, int>> st;
int top[600000];
int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long>::iterator iter;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		top[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && st.top().second < top[i]) {
			st.pop();
		}

		if (st.empty()) {
			cout << 0 << ' ';
		}
		else {
			cout << st.top().first << ' ';
		}
		st.push({ i,top[i] });
	}

}
```
-------
### 정리
1. 자기보다 큰 값이 있을 때 앞에 받은 값과 비교하여 처리해야한다? -> 스택
2. 시간초과 생각해서 구현하기
3. 인덱스를 찾는 find 함수는 시간복잡도가 O(N)이 pair처리를 통해 시간복잡도를 절약하자!
