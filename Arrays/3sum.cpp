#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    vector<int>arr={-1,0,1,2,-1,-4};
    int n=arr.size();
    unordered_set<int>s;
    int sum=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s.find(sum-arr[i]-arr[j])!=s.end()){
                cout<<sum-arr[i]-arr[j]<<" "<<arr[i]<<" "<<arr[j]<<endl;
            
            }
        }
        s.insert(arr[i]);
    }
    return 0;
}