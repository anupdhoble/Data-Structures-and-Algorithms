#include<iostream>
#include<vector>
using namespace std;

double findMedian(vector<int>arr1,vector<int>arr2){
    int n=arr1.size(),m=arr2.size();
    int l=0,h=n,left=(n+m+1)/2;
    if(n>m) return findMedian(arr2,arr1);
    while(l<=h){
        int mid=l+(h-l)/2;
        int mid2=left-mid;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid < n) r1 = arr1[mid];
        if (mid2 < m) r2 = arr2[mid2];
        if (mid - 1 >= 0) l1 = arr1[mid - 1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
        if(l1<=r2 &&l2<=r1){
            if((n+m)%2==1) return max(l1,l2);
            else return (max(l1,l2)+min(r1,r2)/2.0);
        }
        else if(l1>r2) h=mid-1;
        else l=mid+1;
    }
    return 0;
}

int main(){
    vector<int>arr1={1, 4, 7, 10, 12};
    vector<int>arr2={2, 3, 6, 15};
    cout<<findMedian(arr1,arr2);
    return 0;
}