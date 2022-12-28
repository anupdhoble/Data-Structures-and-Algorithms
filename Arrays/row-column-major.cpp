#include<bits/stdc++.h>
using namespace std;
const int n=2;//row
const int m=3;//column
void display(int a[n][m]){
    cout<<"Resultant Array:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void row_maj(int a[n][m]){
    cout<<"Enter elements one by one:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    display(a);
}
void col_maj(int a[n][m]){
    cout<<"Enter elements one by one:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[j][i];
        }
    }
    display(a);
}
int main()
{
    // cout<<"Enter no. of rows:\n";
    // cin>>n;
    // cout<<"Enter no. of columns:\n";
    // cin>>m;
    int arr[n][m];
    int c;
    cout<<"Enter 1 for row maj and 2 for col maj:\n";
    cin>>c;
    if(c==1){
        row_maj(arr);
    }
    else{
        col_maj(arr);
    }
    return 0;
}