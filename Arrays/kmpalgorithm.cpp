#include<bits/stdc++.h>

using namespace std;


vector<int> makelps(string pat){

    int n=pat.size();

    if(n<=1) return {n-1};
    vector<int>lps(n);
    int len=0,i=1;

    while(i<n){
        if(pat[len]==pat[i]){
            lps[i]=++len;i++;
        }else{
            if(len!=0){
                len=lps[len-1]; // we placed len to last matching combination a step back in pat, wo we now will check from here so we havent written i++;
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;

}

int main(){
    //find index where pattern is found
    string txt,pat;
    cin>>txt>>pat;
    vector<int>ans;
    int n=txt.size(),m=pat.size();
    vector<int>lps = makelps(pat);
    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            j++;i++;
        }

        if(j==m){
            ans.push_back(i-j);//pattern found at index
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }

    for(auto it:ans) cout<<it<<" ";

    return 0;
}