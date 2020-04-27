#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        if(nums.empty()) return 0;//数组为空时输入任何数据序号都是0
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        //考察的是折半查找失败时 low指向的位置就是该数据应该插入的位置
        return low;
    }
};
int main(){//测试
    Solution answer;
    vector<int> nums={1,3,5,6,7};
    int target=3;
    int pos=answer.searchInsert(nums,target);
    cout<<pos;
    return 0;
}

