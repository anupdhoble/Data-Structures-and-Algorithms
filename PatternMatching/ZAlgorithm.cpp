#include<bits/stdc++.h>
using namespace std;
vector<int> Zalgorithm(string s) {
    int n = s.size();
    vector<int> arr(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i <= R) {
            // If within the current [L, R] window, reuse the value from arr
            arr[i] = min(R - i + 1, arr[i - L]);
        }
        // Try to extend the match beyond R
        while (i + arr[i] < n && s[arr[i]] == s[i + arr[i]]) {
            arr[i]++;
        }
        // Update the range [L, R]
        if (i + arr[i] - 1 > R) {
            L = i;
            R = i + arr[i] - 1;
        }
    }
    
    return arr;
}
int main(){
    string text,pattern;
    // cin>>text>>pattern;
    // pattern.append("$$");
    // pattern.append(text);
    cin>>pattern;
    vector<int> ans;
    ans = Zalgorithm(pattern);
    cout<<pattern<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}

//aabxaabxcaabxaabxay
// 0 1 0 0 4 1 0 0 0 8 1 0 0 5 1 0 0 1 0 