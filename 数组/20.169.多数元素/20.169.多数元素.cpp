class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     map<int,int> m;
    //     int majority=0,count=0;
    //     for(int i=0;i<nums.size();++i){
    //         m[nums[i]]++;
    //         if(m[nums[i]]>count){
    //             majority=nums[i];
    //             count=m[nums[i]];
    //         }
    //     }
    //     return majority;
    // }
    int majorityElement(vector<int>& nums){
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};