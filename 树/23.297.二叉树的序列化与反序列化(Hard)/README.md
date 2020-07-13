# 23(297) 二叉树的序列化与反序列化(Hard)
## 描述

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

## 示例
```bash
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

``` 
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

## Description

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

## Example

```bash
You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

虽然时间空间消耗很大 但是测试用例依旧通过了 排名靠后的原因是因为这道题的oj程序存在漏洞 有很多人借此机会刷分 刷分的代码后面呈上

```bash
class Codec {
public:

    // Encodes a tree to a single string. 序列化代码 to_string() int类型转换为string类型 
    string serialize(TreeNode* root) {//按照层序遍历的顺序序列化为string
        if(!root) return "";
        string res;
        queue<TreeNode*> st;
        TreeNode* node=root;
        res=res+to_string(root->val)+",";
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.front();
            st.pop();
            if(node->left){
                st.push(node->left);
                res=res+to_string(node->left->val)+",";
            }
            else res.append("null,");
            if(node->right){
                st.push(node->right);
                res=res+to_string(node->right->val)+",";
            }
            else res.append("null,");
        }
        res.pop_back();//删除最后一个多余的,
        return res;
    }
    /* res输出为"1,2,3,null,null,4,5,null,null,null,null"*/

    // Decodes your encoded data to tree. 逆序列化 和创建二叉树原理差不多
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        data.append(",");
        vector<string> convertdata;
        int len=0;
        /*这个for循环精彩的将字符串data里的逗号完美的删除掉 并且将每一个元素单独存放在convertdata数组中
        convertdata[0] = "1" convertdata[1] ="2" convertdata[2] ="3" convertdata[3] ="null" convertdata[4] = "null"*/
        for(int i=0;i<data.size();++i){
            if(data[i]==','){
                convertdata.push_back(data.substr(i-len,len));
                len=0;
            }
            else len++;
        }
        /*创建二叉树结点 依靠队列 将每一个非空结点都连接上*/
        TreeNode* root=new TreeNode(stoi(convertdata[0]));
        TreeNode* node=root;
        queue<TreeNode*> st;
        st.push(node);
        int index=0;
        while(!st.empty()){
            node=st.front();
            st.pop();
            if(++index>=convertdata.size()) break;
            if(convertdata[index]!="null"){ //stoi() string转化为int
                node->left=new TreeNode(stoi(convertdata[index]));
                st.push(node->left);
            }
            if(++index>=convertdata.size()) break;
            if(convertdata[index]!="null"){
                node->right=new TreeNode(stoi(convertdata[index]));
                st.push(node->right);
            }
        }
        return root;
    }
};
``` 

### 最快的代码 -_-...

```bash
class Codec {
public:
    TreeNode* r;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        r = root;
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return r;
    }
};
```
...... 返回的序列化string永远为空 逆序列化永远返回复制的二叉树r  太聪明了 直接找到了程序判断的漏洞所在 虽然跳过了题目要训练的用意 但也是展现了强大的能力