#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;//进位
        for(int i=digits.size()-1;i>=0;i--){
            int val=digits[i]+carry;
            carry=val/10;//大于10就进位
            digits[i]=val%10;//剩的低位
        }
        if(carry==0) return digits;//最高位不是9 
        else{//全是9的情况 
            vector<int> result(digits.size()+1,1);//数组result用n+1个1初始化 
            for(int i=1;i<result.size();i++){//新数组最高位必然是1 其余必然是0
                result[i]=digits[i-1];//错位赋值
            }
            return result;
        }
    }
};
int main()
{
    vector<int> digits={9,9,9};
    Solution answer;
    vector<int> result =answer.plusOne(digits);
    for(auto x:result) cout<<x<<" ";
    return 0;
}
