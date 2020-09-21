# 54(59) 螺旋矩阵Ⅱ(Medium)

## 描述

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

## 示例

```bash

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

``` 

## Description

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

## Example

```bash

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

与[螺旋矩阵](https://github.com/shaoyuanhangyes/LeetCode/tree/master/%E6%95%B0%E7%BB%84/53.54.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5(Medium))思想基本相同 只不过Ⅰ是取数 Ⅱ是填数 循环移动填充即可

### 代码

```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int num=1;
        int up=0,down=n-1,left=0,right=n-1;
        while(true){
            for(int i=left;i<=right;++i){
                res[up][i]=num++;
            }
            if(++up>down) break;
            for(int i=up;i<=down;++i){
                res[i][right]=num++;
            }
            if(--right<left) break;
            for(int i=right;i>=left;--i){
                res[down][i]=num++;
            }
            if(--down<up) break;
            for(int i=down;i>=up;--i){
                res[i][left]=num++;
            }
            if(++left>right) break;
        }
        return res;
    }
};
```