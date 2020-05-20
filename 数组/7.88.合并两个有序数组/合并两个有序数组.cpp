#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=nums1.size()-1;//i指向nums1中要插入的位置
        int p1=m-1;//p1指向nums1中要比较的元素的位置
        int p2=n-1;//p2指向nums2中要比较的元素的位置
        while (p1>=0&&p2>=0){//循环条件:p1 p2有一个遍历完数组就退出循环
            if(nums1[p1]<nums2[p2]){
                nums1[i--]=nums2[p2--];
            }
            else{
                nums1[i--]=nums1[p1--];
            }
        }//三种情况
        /*1.nums1中元素都比nums2中的元素值要小 因此把nums2元素复制到nums1尾部即可 直接通过
          2.nums1中元素都比nums2中的元素值要大 nums1元素依序复制到尾部 然后将nums2中元素复制到nums1中剩下的位置
          3.12混合情况 nums1与nums2中元素互有大小 循环到最后数组内剩余元素一定会出现12情况*/
        while (p2>=0) nums1[i--]=nums2[p2--];//p1遍历完 p2还剩余 将nums2中元素依次复制到nums1中剩余的位置
    }
};
int main()
{
    vector<int> nums1={1,0,0};
    vector<int> nums2={1,2};
    Solution answer1;//情况1
    answer1.merge(nums1,nums1.size()-nums2.size(),nums2,nums2.size());
    for(auto x:nums1) cout<<x<<" ";
	cout<<endl; 
    vector<int> nums3={3,4,5,0,0};
    vector<int> nums4={1,2};//情况2
    answer1.merge(nums3,nums3.size()-nums4.size(),nums4,nums4.size());
    for(auto x:nums3) cout<<x<<" ";
    return 0;
}
