#include <bits/stdc++.h>
using namespace std;


int rob(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];dp[1]=nums[1];
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;

    vector<int>ans(n,0);
    for(int i=0;i<n;i++){

        cin>>ans[i];
    }
    cout<<rob(ans);
    return 0;
}