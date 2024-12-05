#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

    string input;
    getline(cin,input);
    vector<int>arr;
    int a=0,p=0,count=0;
    for(int i=input.size()-1;i>=0;i--){

        if(input[i]==' '){
            arr.push_back(a);
            p=0,a=0;
        }else{
            a+= (input[i]-'0')*pow(10,p++);
            if(i==0){
                arr.push_back(a);
            }
        }
    }
    
    for(int i=0;i<(int)arr.size();i++){
        int a= sqrt(arr[i]);
        if(a*a == arr[i]) count++;
    }

    cout<<count;


    return 0;
}