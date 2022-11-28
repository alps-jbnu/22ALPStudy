//#include <bits/stdc++.h>
//
//char c = '"';
//int count;
//
//void what_is_recursive(int n) {
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << c << "재귀함수가 뭔가요?" << c << "\n";
//	if (n == 0) {
//		for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//		std::cout << c << "재귀함수는 자기 자신을 호출하는 함수라네" << c << "\n";
//		for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//		std::cout << "라고 답변하였지.\n";
//		return;
//	}
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << c << "잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어." << c << "\n";
//	what_is_recursive(n - 1);
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << "라고 답변하였지.\n";
//}
//
//int main() {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//	count = n;
//
//	std::cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
//	what_is_recursive(n);
//	return 0;
//}