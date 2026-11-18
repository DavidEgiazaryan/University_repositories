//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Lenta {
//private:
//	std::vector<int> stack, mini;
//	std::vector<pair<string,int>> history;
//public:
//
//	void stash(int x){
//		stack.push_back(x);
//		if (mini.empty())
//			mini.push_back(x);
//		else
//			mini.push_back(min(mini.back(), x));
//		history.push_back({"stash",x });
//	}
//
//	void burn() {
//		int x = stack.back();
//		stack.pop_back();
//		mini.pop_back();
//		history.push_back({ "burn", x });
//	};
//
//	int oracle(){
//		return mini.back();
//	};
//
//	void rewind(){
//		if (history.back().first == "stash")
//		{
//			stack.pop_back();
//			mini.pop_back();
//			history.pop_back();
//		}
//		else {
//			stack.push_back(history.back().second);
//			if (mini.empty()) mini.push_back(history.back().second);
//			else mini.push_back(min(mini.back(), history.back().second));
//			history.pop_back();
//		}
//	}
//			};
//int main(){
//	int i;
//	cin >> i;
//	Lenta lentapepla;
//	string command;
//
//	while (i--) {
//		cin >> command;
//		if (command == "stash") {
//			int x;
//			cin >> x;
//			lentapepla.stash(x);
//		}
//
//		if (command == "burn") {
//			lentapepla.burn();
//		}
//		
//		if (command == "oracle") {
//			cout<<lentapepla.oracle()<<"\n";
//		}
//
//		if (command == "rewind") {
//			lentapepla.rewind();
//		}
//
//	}
//};
