//#include <queue>
//#include <vector>
//#include <functional>
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	std::priority_queue<int> maxi;
//	
//	int n, k;
//	cin >> n >> k;
//	vector<int> potok(n);
//	for (int i = 0; i < n; i++) {
//		cin >> potok[i];
//	}
//	for (int i = 0; i<n; i++) {
//		maxi.push(potok[i]);
//		if (maxi.size() < k) {
//			cout << "warmup" << "\n";
//		}
//		else
//			if (maxi.size() > k) {
//				maxi.pop();
//				cout << maxi.top() << "\n";
//				}
//			else
//				cout << maxi.top()<< "\n";
//		}
//
//	}