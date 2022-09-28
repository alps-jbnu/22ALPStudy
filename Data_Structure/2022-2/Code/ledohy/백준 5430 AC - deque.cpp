//#include <iostream>
//#include <deque>
//#include <string.h>
//
//int main() {
//
//	char c;
//	std::string fc;
//
//	int idx;
//
//	std::deque<int> dq;
//	
//	int test = 0;
//	std::cin >> test;
//
//	while (test--) {
//
//		dq.clear();
//
//		int rev_flag = 0, error_flag = 0;
//
//		std::cin >> fc >> idx;
//
//		int* arr;
//		arr = new int[idx];
//
//		std::cin >> c;
//		for (int i = 0; i < idx; i++) {
//
//			if (i != 0) std::cin >> c;
//
//			std::cin >> arr[i];
//			dq.push_back(arr[i]);
//		}
//		std::cin >> c;
//
//		for (int i = 0; i < fc.length(); i++) {
//
//			if (fc[i] == 'R') {
//				if (rev_flag == 0) rev_flag = 1;
//				else               rev_flag = 0;
//			}
//
//			if (fc[i] == 'D') {
//
//				if (dq.size() == 0) {
//					error_flag = 1;
//					break;
//				}
//
//				if (rev_flag == 0) dq.pop_front();
//				else               dq.pop_back();
//			}
//
//		}
//
//		if (error_flag == 1) {
//
//			std::cout << "error" << '\n';
//			continue;
//		}
//		if (rev_flag == 0) {
//			std::cout << '[';
//			for (int i = 0; i < dq.size(); i++) {
//				if (i != 0) std::cout << ',';
//
//				std::cout << dq[i];
//			}
//			std::cout << ']' << '\n';
//		}
//		if (rev_flag == 1) {
//			std::cout << '[';
//			for (int i = dq.size() - 1; i >= 0; i--) {
//				if (i != dq.size() - 1) std::cout << ',';
//
//				std::cout << dq[i];
//			}
//			std::cout << ']' << '\n';
//		}
//
//	}
//}