class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=1;
        int temp=1;
        for(int i=0;i+1<nums.size();++i){
            if(nums[i+1]>nums[i]){
                temp++;
            }
            else{
                temp=1;
            }
            res=max(res,temp);
        }
        return res;
    }
};