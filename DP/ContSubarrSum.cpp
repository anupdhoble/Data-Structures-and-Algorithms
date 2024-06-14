#include <bits/stdc++.h>
using namespace std;

// bool solve(vector<int>&nums,int k,int i){

// }
bool checkSubarraySum(vector<int>& nums, int k){
    int n=nums.size();
    cout<<nums[0]<<" ";
    for(int i=1;i<n;i++){
        nums[i]=nums[i]+nums[i-1];
        cout<<nums[i]<<" ";
    }


    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if((nums[i]-nums[j]) ==k ){
                
                return true;
            }
        }
    }
    return false;

    
}
int main(){
    int n,k;
    cin>>n>>k;

    vector<int>ans(n,0);
    for(int i=0;i<n;i++){

        cin>>ans[i];
    }
    if (checkSubarraySum(ans,k)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}