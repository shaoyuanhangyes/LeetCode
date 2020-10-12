#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int sp=1;
        for(int fp=2;fp<nums.size();++fp){
            if(nums[sp-1]!=nums[fp]) nums[++sp]=nums[fp];
        }
        return sp+1;
    }
};

int main(){
    vector<int> nums={1,1,1,2,2,3};
    Solution ans;
    cout<<ans.removeDuplicates(nums);
}