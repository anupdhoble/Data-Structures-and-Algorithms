#include<iostream>
using namespace std;

void swap(int *l,int *r){
    int temp =*l;
    *l=*r;
    *r=temp;
}
void revarray(int a[],int l,int r){
    if(r<=l){
        return;
    }
    swap(a[l],a[r]);
    revarray(a,l+1,r-1);
}
int main(){
    cout<<"initial array: 1 2 3 4 5";
    int a[5]={1,2,3,4,5};
    revarray(a,0,4);
    cout<<"\nAfter reversed: ";
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}