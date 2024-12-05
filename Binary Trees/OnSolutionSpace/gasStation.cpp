#include<iostream>
#include<queue>
#include<utility>
using namespace std;

bool isPossible(double mid,vector<double>&arr){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i+1]-arr[i] >mid) return false;
    }
    return true;
}

double binarySearch(vector<double>&arr){
    double n=arr.size();
    double l=0,h=arr[n-1]-arr[0],ans=0.0;
    double limit = 1e-6;
    while(h-l > (limit)){
        double mid =l+(h-l)/2;
        if(isPossible(mid,arr)){
            ans=mid;
            h=mid;
        }else{
            l=mid;
        }
    }
    return ans;
}
int main(){
    vector<double>arr={3,6,12,19,33,44,67,72,89,95};
    double k=2,n=arr.size();
    priority_queue<pair<double,double>>q;
    for(double i=0;i<n-1;i++){
        q.push({arr[i+1]-arr[i],i});
    }
    vector<double>fl(n,-1);
    while(k--){
        fl[q.top().second]=1;q.pop();
    }
    double j=0;

    for(double i=0;i<arr.size();i++){
        if(j>=n) break;
        if(fl[j]==1){
            arr.insert(arr.begin()+i+1,(arr[i]+arr[i+1])/2);
            i++;
        }
        j++;

    }
    cout<<binarySearch(arr);
    return 0;
}
