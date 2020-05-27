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
