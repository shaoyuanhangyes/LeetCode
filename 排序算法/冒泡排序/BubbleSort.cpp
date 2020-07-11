#include <iostream>
#include <vector>

using namespace std;
void sort(int &i,int &j){
    int t=i;i=j;j=t;
}
void BubbleSort(vector<int>& nums){
    for(int i=0;i<nums.size();++i){
        for(int j=nums.size()-1;j>i;j--){
            if(nums[j]<nums[j-1]) sort(nums[j],nums[j-1]);
        }
    }
}
int main(){
    vector<int> nums={98,36,-9,0,47,23,1,8,10,7};
    for(auto x:nums) cout<<x<<" ";
    cout<<endl;
    BubbleSort(nums);
    cout<<"-------------------------"<<endl;
    for(auto x:nums) cout<<x<<" ";
    return 0;
}
