// arr[] ={2,3,6,7}  target=7 repetition allowed
#include<iostream>
#include <vector>
using namespace std;

void combisum(int i,int target,vector<int>v,int arr[],int n){
    if(target==0&&i==n){
        cout<<"#";
        for(int num:v){
            cout<<num<<" ";
        }
        cout<<"#";
        cout<<endl;
        return;
    }
    if(i==n){
        return;
    }
    if(target>=arr[i]){v.push_back(arr[i]);
    combisum(i,target-arr[i],v,arr,n);
    v.pop_back();}
    combisum(i+1,target,v,arr,n);
}
using namespace std;
int main()
{
    int arr[]={2,3,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>v;
    combisum(0,7,v,arr,n);
    return 0;
}