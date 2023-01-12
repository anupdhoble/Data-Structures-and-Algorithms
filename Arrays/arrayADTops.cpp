#include<bits/stdc++.h>
using namespace std;
const int n=3;//row
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
void transposed(int arr[n][m]){
    cout<<"Enter elements one by one:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\nTransposed matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<"\n";
    }
}
void mat_addi(int arr[n][m]){
    int arr2[n][m];
    cout<<"Enter first matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter Second matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"Result matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]+arr2[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void mat_multi(int arr[n][m]){
     int arr2[n][m],ans[n][m];
    cout<<"Enter first matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter Second matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"Resultunt matrix:-\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=0;
            for(int k=0;k<m;k++){
                ans[i][j]+=arr[i][k]*arr2[k][j];
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int arr[n][m];
    int c;
    while(1){
    cout<<"MENU:-\n1. Row major display\n2. Column major display\n3. Display transpose\n4. Matrix addition\n5. Matrix Multiplication\n6. Exit\n";
    cin>>c;
    
    switch(c){
        case 1:
            row_maj(arr);
            break;
        case 2:
            col_maj(arr);
            break;
        case 3:
            transposed(arr);
            break;
        case 4:
            mat_addi(arr);
            break;
        case 5:
            mat_multi(arr);
            break;
        case 6:
            exit(0);
    }}
    return 0;
}