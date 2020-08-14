# 3(20) 有效的括号

## 描述

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

## 示例
```bash

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

``` 

`BitDance` `Bilibili` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei` `JD` `Baidu` `Cisco` `Mi` `DiDi` `Linkedln` `BiliBili` `Intel`

## 解题

```bash

class Solution {
public:
    bool isMatch(char c1,char c2){
        if(c1=='['&&c2==']') return true;
        if(c1=='{'&&c2=='}') return true;
        if(c1=='('&&c2==')') return true;
        return false;
    }
    bool isValid(string s) {
        if(s.length()%2==1) return false;
        stack<char> st;
        if(s.empty()) return true;
        st.push(s[0]);
        for(int i=1;i<s.length();++i){
            if(!st.empty()&&isMatch(st.top(),s[i])) st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
};

```