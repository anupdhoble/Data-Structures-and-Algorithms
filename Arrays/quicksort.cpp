#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int l,int r)
{
    int piviot=a[r];
    int i=l-1,j=r-1;
    while(i<j)
    {
        while(a[++i]<=piviot);
        while(j>l && a[--j]>piviot);
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;
}

void quick_sort(int a[],int l,int r)
{
    if(l<r){
        int piviot=partition(a,l,r);
        quick_sort(a,l,piviot-1);
        quick_sort(a,piviot+1,r);
    }
}

int main()
{
    int a[]={7,5,2,14,7,9,6,2};
    quick_sort(a,0,7);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
