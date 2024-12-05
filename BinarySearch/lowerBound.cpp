#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findlowerbound(vector<long long> v, long long n, long long x) {
        long long prev = -1; // Initialize to -1 to indicate not found
        long long l = 0, h = v.size() - 1;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (v[mid] >= x) {
                h = mid - 1;
                prev = mid;
            } else {
                l = mid + 1;
            }
        }
        return prev;
    }
};
int main(){
    Solution obj;
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << obj.findlowerbound(v, n, x);
    return 0;
}