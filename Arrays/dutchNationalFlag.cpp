#include<iostream>
#include<vector>
using namespace std;

void swap(int & a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
vector<int> solve(vector<int>arr,int n){
    if(n<=1) return arr;
    int l=0,m=0,r=n-1;
    while(arr[l]==0)l++;
    m=l;
    while(arr[r]==2)r--;
    
    while(m<=r){
        if(arr[m]==0){
            swap(arr[m],arr[l]);
            l++;
        }else if(arr[m]==2){
            swap(arr[m],arr[r]);
            r--;
        }
        else{
            m++;
        }
        if(l>m) m=l;
    }
    return arr;
}


int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans = solve(arr,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}