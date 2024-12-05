#include<iostream>
#include<string>
using namespace std;

void solve(int i,int k,string s,int one){
    if(i==k) {cout<<s<<" ";return;}
    
    solve(i+1,k,s+'0',0);
    if(!one)solve(i+1,k,s+'1',1);
}
int main(){
    solve(0,3,"",0);
    return 0;
}