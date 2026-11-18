//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//
//    long long n;
//    long long S;
//    cin >> n >> S;
//
//    vector<long long> a(n);
//    for (long long i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    long long sum =0;
//    long long ans = 0;
//    long long l = 0;
//    for (long long r = 0; r<n; r++)
//    {
//		sum += a[r];
//        while (sum > S)
//        {
//            sum -= a[l];
//            l++;
//        }
//        ans = max(ans, r - l + 1);
//    }
//    cout << ans << endl;
//
//    return 0;
//}