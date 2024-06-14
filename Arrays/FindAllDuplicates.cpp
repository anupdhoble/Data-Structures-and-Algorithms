#include <iostream>
#include <vector>

using namespace std;


vector<int> findDuplicates(vector<int>& nums) {
    // We know 1<=arr[i]<=n;
    // We can visit index of current value (as a index) and mark it -1
    // So next time if we encounter -1 again we know that somenumber is already pointing to it 
    // And guess what we got the duplicate;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            if(nums[-nums[i]-1]<0){
            ans.push_back(-nums[i]);
        }
        else{
            nums[-nums[i]-1]*=(-1);
        }
        }else{
            if(nums[nums[i]-1]<0){
            ans.push_back(nums[i]);
        }
        else{
            nums[nums[i]-1]*=(-1);
        }
        }
    }
    return ans;
}

// Main function
int main() {
    vector<int>arr={4,3,2,7,8,2,3,1};
    vector<int>ans=findDuplicates(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}