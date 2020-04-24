#include<iostream>
#include<vector>
#include<map>
using namespace std; 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;//first��nums��ֵ second������� 
        vector<int> result;//������� 
        for(int i=0;i<nums.size();++i){
            if(m.find(nums[i])==m.end()){//δ�ҵ� 
                m[target-nums[i]]=i;//m[7]=0;m[2]=1;break;���治������m[-2]=3;m[-6]=4 
            }
            else{
                result.push_back(m[nums[i]]);//m[7]=0 0����result 
                result.push_back(i);//i=1 1����result 
                break;//��Ŀǿ��ÿ������ֻ��Ӧһ���� ����break��ʡ�ռ� 
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
