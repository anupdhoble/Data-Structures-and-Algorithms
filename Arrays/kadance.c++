#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    int maxi=INT_MIN;
    int CurrSum=0;
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        CurrSum+=arr[i];
        maxi=max(maxi,CurrSum);
        if(CurrSum<0) CurrSum=0;
    }
    cout<<maxi;
    return 0;
}