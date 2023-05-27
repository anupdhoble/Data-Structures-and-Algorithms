#include <iostream>
using namespace std;


//parametrised way
void psum(int n,int sum){
    if(n<1){
        cout<<"parameterised way sum: "<<sum<<"\n";
        return;
    }
    psum(n-1,sum+n);
}
//functional way
int fsum(int n){
    if(n==0){
        return 0;
    }
    return n+fsum(n-1);
}
int main(){
    psum(4,0);
    cout<<"Functional way: "<<fsum(4);
    return 0;
}