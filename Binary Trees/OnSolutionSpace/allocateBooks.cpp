#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool isPossible(int mid,vector<int>&arr,int n,int m){
    int students=1,currPages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;       
        if(currPages+arr[i] >mid){
            currPages=arr[i];
            students++;
        }else{
            currPages+=arr[i];
        }
    }
    return students<=m;
}
int findPages(vector<int>&arr,int n,int m){
    int l =0,h,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    h=sum;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(isPossible(mid,arr,n,m)){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr= {12, 34, 67, 90};
    int n=4,m=2;
    cout<<findPages(arr,n,m);
    return 0;
}