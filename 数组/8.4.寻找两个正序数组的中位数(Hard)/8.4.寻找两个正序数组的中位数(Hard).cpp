#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*��λ���������ǰ�һ�����ϻ���Ϊ����������ȵļ��� ����һ���Ӽ��е�Ԫ�����Ǵ�����һ���Ӽ��е�Ԫ��*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        if(len1>len2) return findMedianSortedArrays(nums2,nums1);//ȷ����һ�����ε����鳤������̵� ��ΪҪ�Զ�������ж��ֲ���
        int LMax1,LMax2,RMin1,RMin2,c1,c2,low=0,high=2*len1;
        while(low<=high){//�Գ��Ƚ϶̵�������ж��ֲ���ȷ��c1��λ��
            c1=(low+high)/2;
            c2=len1+len2-c1;

            LMax1=(c1==0)?INT_MIN:nums1[(c1-1)/2];
            RMin1=(c1==2*len1)?INT_MAX:nums1[c1/2];
            LMax2=(c2==0)?INT_MIN:nums2[(c2-1)/2];
            RMin2=(c2==2*len2)?INT_MAX:nums2[c2/2];

            if(LMax1>RMin2) high=c1-1;
            else if(LMax2>RMin1) low=c1+1;
            else break;
        }
        return (max(LMax1,LMax2)+min(RMin1,RMin2))/2.0;
    }
    int max(int n1,int n2){//�����������е����ֵ
        if(n1>n2) return n1;
        else return n2;
    }
    int min(int n1,int n2){//�����������е���Сֵ
        if(n1<n2) return n1;
        else return n2;
    }
};
int main(){
    vector<int> nums1={2,3,5};
    vector<int> nums2={1,4,7,9};
    Solution answer;
    double res=answer.findMedianSortedArrays(nums1,nums2);
    cout<<res<<endl;
    return 0;
}
