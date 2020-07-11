# 冒泡排序(BubbleSort)

## 代码

```bash
void sort(int &i,int &j){
    int t=i;i=j;j=t;
}
void BubbleSort(vector<int>& nums){
    for(int i=0;i<nums.size();++i){
        for(int j=nums.size()-1;j>i;j--){
            if(nums[j]<nums[j-1]) sort(nums[j],nums[j-1]);
        }
    }
}
int main(){
    vector<int> nums={98,36,-9,0,47,23,1,8,10,7};
    for(auto x:nums) cout<<x<<" ";
    cout<<endl;
    BubbleSort(nums);
    cout<<"-------------------------"<<endl;
    for(auto x:nums) cout<<x<<" ";
    return 0;
}
```

```bash
Original: 98  36  -9  0  47  23   1   8   10   7
------------------------------------------------
Updated:  -9   0   1  7   8  10  23  36   47  98
```

### 代码剖析

冒泡排序 分内外两个循环 内循环找出此次过程中最小的元素放在首位 外循环控制循环的范围
内循环从尾部开始 寻找到最小的元素放在此次范围的首位 外循环每隔一次就向后缩减循环范围

因此 冒泡排序每一趟排序都会将一个元素放置在它的最终位置上

### 性能分析

空间复杂度: 冒泡排序仅使用了常数个辅助单元 因而空间复杂度O(1)

时间复杂度: 最坏情况下时间复杂度<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><msup><mi>n</mi><mn>2</mn></msup><mo stretchy="false">)</mo></math> 平均时间复杂度<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><msup><mi>n</mi><mn>2</mn></msup><mo stretchy="false">)</mo></math>

稳定性: 冒泡排序是一种稳定的排序方法