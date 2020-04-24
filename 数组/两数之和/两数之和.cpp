#include<iostream>
#include<vector>
#include<map>
using namespace std; 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;//first存nums的值 second存迭代器 
        vector<int> result;//结果数组 
        for(int i=0;i<nums.size();++i){
            if(m.find(nums[i])==m.end()){//未找到 
                m[target-nums[i]]=i;//m[7]=0;m[2]=1;break;后面不用运行m[-2]=3;m[-6]=4 
            }
            else{
                result.push_back(m[nums[i]]);//m[7]=0 0存入result 
                result.push_back(i);//i=1 1存入result 
                break;//题目强调每种输入只对应一个答案 所以break节省空间 
            }
        }
        return result;
    }
};
int main(){
	Solution answer;
	vector<int> nums={2,7,11,15};
	int target=9;
	vector<int> result=answer.twoSum(nums,target);
	for(auto x:result) cout<<x<<" ";
} 
