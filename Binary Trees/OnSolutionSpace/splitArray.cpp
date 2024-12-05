#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>&arr,int k,int sum,int mid){
    int split=1,currSum=0;
    for(int i=0;i<arr.size();i++){
        if(currSum+arr[i]>mid){
            currSum=arr[i];
            split++;
        }else{
            currSum+=arr[i];
        }
    }
    return split<= k;
}
int findBinary(vector<int>&arr,int k,int sum){
    int l=0,h=sum,ans=0;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(isPossible(arr,k,sum,mid)){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr={7,2,5,10,8};
    int k=2;
    int sum=0;
    for(auto it: arr){
        sum+=it;
    }
    cout<<findBinary(arr,k,sum);

    return 0;
}