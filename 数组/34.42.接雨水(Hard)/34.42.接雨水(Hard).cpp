#include <iostream>
#include <vector>

using namespace std;


//class Solution {//按列暴力求解
//public:
//    int trap(vector<int>& height) {
//        if(height.empty()) return 0;
//        int sum=0;
//        for(int i=1;i<height.size()-1;++i){
//            int max_left=0;
//            for(int j=i-1;j>=0;--j){
//                if(height[j]>max_left) max_left=height[j];
//            }
//            int max_right=0;
//            for(int j=i+1;j<=height.size()-1;++j){
//                if(height[j]>max_right) max_right=height[j];
//            }
//            int min_both=min(max_left,max_right);
//            if(min_both>height[i]) sum+=(min_both-height[i]);
//        }
//        return sum;
//    }
//};

//class Solution {//优化暴力解法
//public:
//    int trap(vector<int>& height) {
//        if(height.empty()) return 0;
//        int sum=0;
//        int max_left[height.size()];
//        int max_right[height.size()];
//        max_left[0]=max_right[0]=height[0];
//        max_left[height.size()-1]=max_right[height.size()-1];
//        for(int i=1;i<height.size()-1;++i){
//            max_left[i]=max(max_left[i-1],height[i-1]);
//        }
//        for(int i=height.size()-2;i>=0;--i){
//            max_right[i]=max(max_right[i+1],height[i+1]);
//        }
//        for(int i=1;i<height.size()-1;++i){
//            int min_both=min(max_left[i],max_right[i]);
//            if(min_both>height[i]) sum+=(min_both-height[i]);
//        }
//        return sum;
//    }
//};

class Solution {//双指针
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int sum=0;
        int left=0,right=height.size()-1;
        int max_left=height[left],max_right=height[right];
        while(left<right){
            max_left=max(max_left,height[left]);
            max_right=max(max_right,height[right]);
            if(max_left<max_right){
                sum+=max_left-height[left];
                left++;
            }
            else{
                sum+=max_right-height[right];
                right--;
            }
        }
        return sum;
    }
};

int main(){
    vector<int> height={4,2,3};
    Solution ans;
    cout<<ans.trap(height);
}