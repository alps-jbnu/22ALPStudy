//#include <iostream>
//#include <stack>
//
//int main() {
//
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//
//	unsigned long long sum = 0, bd_count = 0;
//
//	int num;
//	std::cin >> num;
//
//	unsigned long long high;
//
//	std::stack<int> heigh;
//
//	for (int i = 0; i < num; i++) {
//
//		std::cin >> high;
//
//		while (!heigh.empty() && heigh.top() <= high)
//			heigh.pop();
//
//		sum += heigh.size();
//		heigh.push(high);
//	}
//
//	std::cout << sum;
//}