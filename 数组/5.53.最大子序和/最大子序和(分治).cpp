#include<iostream>
#include<vector>
using namespace std;
const int MIN_INT=-32767;//给定极小值
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//分治法
        if(nums.empty()) return 0;//空数组直接返回0
        int max=maxArrayHelper(nums,0,nums.size()-1);
        return max;
    }
    int maxArrayHelper(vector<int> &nums,int left,int right){
        if(left==right) return nums[left];
        int mid=(left+right)/2;
        int leftSum=maxArrayHelper(nums,left,mid);//递归求出左区间的最大值
        int rightSum=maxArrayHelper(nums,mid+1,right);//递归求出右区间的最大值
        int max=MIN_INT;
        if(leftSum>rightSum) max=leftSum;
        else max=rightSum;
        //包含nums[mid]和nums[mid+1]的区间
        int midSum=midSubArray(nums,left,mid,right);//分别求出包含nums[mid]和nums[mid+1]的序列最大值 然后两者相加就是所求的最大值
        if(max<midSum) max=midSum;
        return max;
    }
    int midSubArray(vector<int> &nums,int left,int mid,int right){
        int leftMax=MIN_INT;//若用0初始化 当数组元素为负值时就会出错
        int leftArray=0;
        for(int i=mid;i>=left;i--){
            leftArray+=nums[i];
            if(leftMax<leftArray) leftMax=leftArray;
        }
        int rightMax=MIN_INT;//若用0初始化 当数组元素为负值时就会出错
        int rightArray=0;
        for(int i=mid+1;i<=right;i++){
            rightArray+=nums[i];
            if(rightMax<rightArray) rightMax=rightArray;
        }
        int SumMax=leftMax+rightMax;
        int max=leftMax;
        //三个数比较大小
        if(max<rightMax) max=rightMax;
        if(max<SumMax) max=SumMax;
        return max;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution answer;
    int max=answer.maxSubArray(nums);
    cout<<max;
    return 0;
}