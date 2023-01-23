#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int mid,int r){
    if(l<r){
        
        int n1=mid-l+1,n2=r-mid;
        int p[n1],q[n2];
        for(int i=0;i<n1;i++){
            p[i]=a[l+i];
        }
        for(int i=0;i<n2;i++){
            q[i]=a[mid+i+1];
        }
        int i=0,j=0,poi=l;
        while(i!=n1&&j!=n2){
            if(p[i]<=q[j]){
                a[poi]=p[i];
                i++;
                poi++;
            }
            else{
                a[poi]=q[j];
                j++;
                poi++;
            }
        }
        while(i!=n1){
            a[poi]=p[i];
            poi++;
            i++;
        }
        while(j!=n2){
            a[poi]=q[j];
            poi++;
            j++;
        }
    }
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int a[7]={4,8,6,2,9,7,3};
    cout<<"\nUnsorted Array: ";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    int l=0,r=6;
    mergesort(a,l,r);
    cout<<"\nSorted Array: ";
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}