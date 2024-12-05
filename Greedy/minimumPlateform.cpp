#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
bool mycomb(pair<int,char>&a,pair<int,char>&b){
    if(a.first<b.first){
        return true;
    }else if(a.first>b.first){
        return false;
    }else{
        if(a.second=='a'){
            return true;
        }
    }
    return false;
}
int findMinPlateforms(int arr[],int dept[],int n){
    vector<pair<int,char>>comb;
    for(int i=0;i<n;i++){
        comb.push_back({arr[i],'a'});
    }
    for(int i=0;i<n;i++){
        comb.push_back({dept[i],'d'});
    }
    sort(comb.begin(),comb.end(),mycomb);
    int plateforms=0;
    int currHave=0;
    int m=2*n;
    for(int i=0;i<m;i++){
        if(comb[i].second=='a'){
            currHave++;
        }else{
            currHave--;
        }
        plateforms=max(plateforms,currHave);
    }
    return plateforms;
}
int main(){
    int arr[]={900, 940, 950, 1100, 1500, 1800},
    dept[]={910, 1200, 1120, 1130, 1900, 2000};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Plateforms: ";
    cout<<findMinPlateforms(arr,dept,n);

    return 0;
}