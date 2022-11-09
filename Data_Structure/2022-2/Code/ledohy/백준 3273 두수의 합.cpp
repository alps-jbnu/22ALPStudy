//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	int a, n, target, begin, end;
//	int count = 0;
//	std::vector<int> v;
//
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> a;
//		v.push_back(a);
//	}
//
//	std::cin >> target;
//
//	sort(v.begin(), v.end());
//	begin = 0;
//	end = n - 1;
//
//	while (begin < end)
//	{
//		if (v[begin] + v[end] == target)
//		{
//			count++;
//			begin++;
//			end--;
//		}
//		else if (v[begin] + v[end] > target) end--;
//		else if (v[begin] + v[end] < target) begin++;
//	}
//	std::cout << count;
//}