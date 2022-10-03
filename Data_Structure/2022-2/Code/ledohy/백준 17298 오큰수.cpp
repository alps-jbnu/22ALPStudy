//#include <iostream>
//#include <stack>
//
//int main() {
//
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//
//	int test, num;
//	
//	std::stack<int> st;
//
//	std::cin >> test;
//
//	int* NGE, * flag;
//	NGE = new int[test];
//	flag = new int[test];
//
//	for (int i = 0; i < test; i++) {
//		NGE[i] = -1;
//		flag[i] = 0;
//	}
//
//	int count = 0;
//
//	for (int i = 0; i < test; i++) {
//
//		count = 0;
//
//		std::cin >> num;
//
//		while (!st.empty() && st.top() < num) {
//			st.pop();
//			count++;
//		}
//			
//		for (int j = 0; j < count; j++) {
//
//			if (flag[i - j - 1] == 0) {
//
//				NGE[i - j - 1] = num;
//				flag[i - j - 1]++;
//
//			}
//			else
//				count++;
//
//		}
//			
//
//		st.push(num);
//	}
//	
//	for (int i = 0; i < test; i++)
//		std::cout << NGE[i] << ' ';
//
//	return 0;
//}