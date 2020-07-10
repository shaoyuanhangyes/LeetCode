#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& nums,int left,int right){
    int pivot=nums[left];
    while(left<right){
        while(left<right&&nums[right]>=pivot) right--;
        nums[left]=nums[right];
        while(left<right&&nums[left]<=pivot) left++;
        nums[right]=nums[left];
    }
    nums[left]=pivot;
    return left;
}
void QuickSort(vector<int>& nums,int left,int right){
    if(left<right){
        int pivot=Partition(nums,left,right);
        QuickSort(nums,left,pivot-1);
        QuickSort(nums,pivot+1,right);
    }
}

int main(){
    vector<int> nums={98,36,-9,0,47,23,1,8,10,7};

    for(auto x:nums) cout<<x<<" ";
    cout<<endl;
    QuickSort(nums,0,nums.size()-1);
    cout<<"-------------------------"<<endl;
    for(auto x:nums) cout<<x<<" ";
    return 0;
}