#include<iostream>
#include<string.h>
using namespace std;

bool ispalindrome(string &a,int l,int r){
    if(l>=r){
        return true;
    }
    if(a[l]!=a[r]) return false;

    
    return ispalindrome(a,l+1,r-1);
}
int main(){
    string a="ggabagg";
    cout<<"\n"<<"String: "<<a;
    int n=size(a)-1;
    if(ispalindrome(a,0,n)){
        cout<<"\nIt is palindrome";
    }
    else{
        cout<<"\nIT is not a palindrome";
    }
    return 0;
}