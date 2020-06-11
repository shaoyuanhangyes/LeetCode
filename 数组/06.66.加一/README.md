# 6(66) 加一
## 描述
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
## 示例
```bash
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
``` 

## Description
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.


## Example
```bash
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

```
## 解题

```bash
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

```