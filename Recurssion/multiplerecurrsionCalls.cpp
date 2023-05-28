//Example is fibonnaci series
#include<iostream>
using namespace std;


int fibonnaci(int n){
    if(n<=1) return n;
    return fibonnaci(n-1)+fibonnaci(n-2);
}
int main(){
    int n=4;
    cout<<"Fibonnaci of n is :"<<fibonnaci(n);
    return 0;
}