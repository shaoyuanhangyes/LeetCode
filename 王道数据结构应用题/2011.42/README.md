## 题目

一个长度为L(L>=1) 的升序序列S 处在第[L/2]向下取整 位置上的数为S的中位数 例如 S1={11,13,15,17,19} S2={2,4,6,8,10} 

则S1中位数为15 S1和S2中位数为11 现在有两个等长的生序序列A B 设计一个高效的算法 找出两个序列A和B的中位数

## 解题

先将两个有序数组合并 然后直接返回中位数 输出即可

## 代码

```C++
#include <iostream>

using namespace std;

int mergearray(int* a,int La,int* b,int Lb){
    int i=2*La-1;
    int p1=La-1;
    int p2=Lb-1;
    while(p1>=0&&p2>=0){
        if(a[p1]<b[p2]) a[i--]=b[p2--];
        else a[i--]=a[p1--];
    }
    while(p2>=0) a[i--]=b[p2--];
    return a[10/2];
}

int main(){
    int a[]={11,13,15,17,19,0,0,0,0,0};
    int b[]={2,4,6,8,10};
    cout<<mergearray(a,5,b,5);
}
```