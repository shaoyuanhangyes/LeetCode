#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        int left=1,right=1;
        for(int i=0;i<nums.size();++i){
            output[i]*=left;
            left*=nums[i];
            output[nums.size()-1-i]*=right;
            right*=nums[nums.size()-1-i];
        }
        return output;
    }
};

int main(){
    vector<int> nums={1,2,3,4};
    Solution ans;
    nums=ans.productExceptSelf(nums);
    for(auto x:nums) cout<<x<<" ";
}