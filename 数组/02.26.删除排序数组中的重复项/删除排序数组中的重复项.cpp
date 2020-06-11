#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos=0;//出现一次不同数字 就+1 所以(pos+1)是最后输出数组的长度
        if(nums.empty()) return 0;//如果不判空 在提交代码的时候会无法通过 LeetCode的输入实例中有空数组
        for(int i=0;(i+1)<nums.size();++i){//(i+1)< 若是i 那么下面的i+1执行到最后一个元素时会溢出
            if(nums[i]!=nums[i+1]){//若前后一样就跳过继续循环 
                nums[++pos]=nums[i+1];//前后不一样时把后面第一次出现的数字赋值给(++pos)指向的位置
            }
        }
        return pos+1;
    }
};
int main(){//非空数组实例
    vector<int> nums={1,1,1,2,3};
    Solution answer;
    int len=answer.removeDuplicates(nums);
    for(int i=0;i<len;i++) cout<<nums[i]<<" ";
}
