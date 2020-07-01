# 11(96) 不同的二叉搜索树
## 描述

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

## 示例
```bash

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

``` 

## Description

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

## Example

```bash

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`
## 解题

### 思路
`动态规划`
设n个结点的二叉搜索树个数为`G(n)`
设`f(i)`为以i为根的二叉搜索树的个数 则有以下公式成立

<math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo><mo>=</mo><mi>f</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo><mo>+</mo><mi>f</mi><mo stretchy="false">(</mo><mn>2</mn><mo stretchy="false">)</mo><mo>+</mo><mi>f</mi><mo stretchy="false">(</mo><mn>3</mn><mo stretchy="false">)</mo><mo>+</mo><mo>.</mo><mo>.</mo><mo>.</mo><mo>+</mo><mi>f</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo><mo>+</mo><mi>f</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></math>

当i为根结点的时候 其左子树的结点个数为`i-1` 其右子树的结点个数为`n-i` 则有以下公式成立

<math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>f</mi><mo stretchy="false">(</mo><mi>i</mi><mo stretchy="false">)</mo><mo>=</mo><mi>G</mi><mo stretchy="false">(</mo><mi>i</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo><mo>∗</mo><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mi>i</mi><mo stretchy="false">)</mo></math>

结合两个公式即可得到`卡特兰数`公式(就是用于入栈序列确定 有多少种出栈序列的卡特兰数)

<math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo><mo>=</mo><mi>G</mi><mo stretchy="false">(</mo><mn>0</mn><mo stretchy="false">)</mo><mo>∗</mo><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo><mo>+</mo><mi>G</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo><mo>∗</mo><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>2</mn><mo stretchy="false">)</mo><mo>+</mo><mi>G</mi><mo stretchy="false">(</mo><mn>2</mn><mo stretchy="false">)</mo><mo>∗</mo><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>3</mn><mo stretchy="false">)</mo><mo>+</mo><mo>.</mo><mo>.</mo><mo>.</mo><mo>+</mo><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>2</mn><mo stretchy="false">)</mo><mo>∗</mo><mi>G</mi><mo stretchy="false">(</mo><mn>1</mn><mo stretchy="false">)</mo><mo>+</mo><mi>G</mi><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo><mo>∗</mo><mi>G</mi><mo stretchy="false">(</mo><mn>0</mn><mo stretchy="false">)</mo></math>

### 代码实现

根据思路的分析 其实代码根本没必要将所有的二叉搜索树的形态都构造出来 只需要用代码还原卡特兰数公式即可

```bash
int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
int main(){
    int n;
    cout<<"请输入二叉搜索树结点的个数n=";
    cin>>n;
    cout<<endl
        <<n<<"个结点的二叉搜索树的个数为"
        <<numTrees(n);
    return 0;
}
```

### 代码分析

```

使用了n+1个0初始化名为dp的数组
dp[n]就是n个结点的二叉搜索树的个数
所以理所应当的 dp[0]=1 dp[1]=1 结点数为0 or 1的二叉搜索树个数为1

n<2的时候循环条件无法通过 直接return了
假设输入的n=3 进入for循环 首先计算 dp[2]=dp[0]*dp[1]+dp[1]*dp[0]=1+1=2 然后计算 dp[3]=dp[0]*dp[2]+dp[1]*dp[1]+dp[2]*dp[0]=2+1+2=5

```