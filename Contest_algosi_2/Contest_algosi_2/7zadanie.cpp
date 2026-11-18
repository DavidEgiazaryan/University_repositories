//#include <queue>
//#include <vector>
//#include <functional>
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	std::priority_queue<int> first_half;
//	std::priority_queue<int, std::vector<int>, std::greater<int>> second_half;
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string command;
//		int x;
//		cin >> command;
//		if (command == "beat") {
//			cin >> x;
//			if ( first_half.size() == 0 or x <= first_half.top())
//			{
//				first_half.push(x);
//			}
//			else
//			{
//				second_half.push(x);
//			}
//			if (first_half.size() > second_half.size() + 1)
//			{
//				second_half.push(first_half.top());
//				first_half.pop();
//			}
//			if (first_half.size() < second_half.size())
//			{
//				first_half.push(second_half.top());
//				second_half.pop();
//			}
//			cout << first_half.top() << "\n";
//		}
//	}
//}