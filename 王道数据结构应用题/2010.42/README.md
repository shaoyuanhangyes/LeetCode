## 题目

将n个整数存放在一维数组R中 设计一个高效的算法 将R中保存的序列循环左移p个位置  `0<p<n` 

即将R中数据由(x0,x1...xn-1,xn) 变换为

(xp,xp+1...xn-1,xn,x0,x1...xp-1)

## 题解

reverse(1,2) reverse(3,4,5) reverse(2,1,5,4,3) -> 3 4 5 1 2

```bash
p=2
1 2 3 4 5 -> 2 1|3 4 5 -> 2 1|5 4 3 -> 3 4 5 1 2
```

## 代码

```C++
#include <iostream>

using namespace std;

void reverse(int* r,int start,int end){
    for(int i=0;i<(end-start+1)/2;++i){
        int temp=r[i+start];
        r[i+start]=r[end-i];
        r[end-i]=temp;
    }
}

int main(){
    int R[5]={1,2,3,4,5};
    int n=5;
    int p;
    cout<<"please enter distance:p=";
    cin>>p;
    reverse(R,0,p-1);
    reverse(R,p,n-1);
    reverse(R,0,n-1);
    for(int i=0;i<5;++i) cout<<R[i]<<" ";
    return 1;
}
```