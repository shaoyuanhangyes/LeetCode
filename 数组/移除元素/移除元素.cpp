#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos=0;//原数组长度
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[pos++]=nums[i];//存在一个不为val的值就加入数组
            }
        }
        return pos;
    }
};
int main(){//测试
    vector<int> nums={1,1,1,2,3};
    Solution answer;
    int len=answer.removeElement(nums,1);
    for(int i=0;i<len;i++) cout<<nums[i]<<" ";
}
