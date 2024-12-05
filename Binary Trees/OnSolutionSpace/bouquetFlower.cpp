#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool isPossible(vector<int>&arr,int mid,int k){
    int count=1,n=arr.size();
    int prev=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-prev>=mid){
            prev=arr[i];
            count++;
        }
    }
    return count>=k;
}
int binarySearch(vector<int>&arr,int k){
    int n=arr.size();
    int l=0,h=arr[n-1],ans=-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(isPossible(arr,mid,k)){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {1, 2 ,4 ,8 ,9};
    sort(arr.begin(),arr.end());
    int k=3;
    cout<<binarySearch(arr,k);
    return 0;
}