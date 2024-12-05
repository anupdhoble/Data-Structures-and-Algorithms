#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>monoinc;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!monoinc.empty() && monoinc.top()>arr[i]){
            monoinc.pop();
        }
        if(monoinc.empty()){
            ans[i]=-1;
        }else{
            ans[i]=monoinc.top();
        }
        monoinc.push(arr[i]);
    }
    for(auto it: ans) cout<<it<<" ";
    return 0;
}