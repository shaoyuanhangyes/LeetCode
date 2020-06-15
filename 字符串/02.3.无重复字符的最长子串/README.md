# 2(3) 无重复字符的最长子串
## 描述
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
## 示例
```bash
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
    #请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
``` 
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei` `JD` `Baidu` `Cisco` `Mi` `DiDi` `Linkedln` `BiliBili` `Intel`
## 解题
```bash
#include<iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start(0),end(0),len(0),maxLength(0);
        map<char,int> hash;//hash的first存储字符串s中的字符
        while(end<s.size()){
            char temp=s[end];
            //在hash里寻找end指向的字符
            if(hash.find(temp)!=hash.end()&&hash[temp]>=start){//判断条件为 在hash中寻找到end指向的字符 且这个字符的second值必须>=start
                start=hash[temp]+1;//更新start指向的位置为 在hash寻找到的字符的下一位
                len=end-start;//更新len
            }
            //没有寻找到就将end指向的字符添加到hash里 同时更新子串长度和最大长度
            hash[temp]=end;
            end++;
            len++;
            if(len>maxLength) maxLength=len;
        }
        return maxLength;
    }
};
int main(){
    string s="abcabcbb";
    Solution answer;
    int len=answer.lengthOfLongestSubstring(s);
    cout<<len<<endl;
    return 0;
}

```