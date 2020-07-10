# 快速排序(QuickSort)

## 代码

```bash
int Partition(vector<int>& nums,int left,int right){
    int key=nums[left];
    while(left<right){
        while(left<right&&nums[right]>=key) right--;
        nums[left]=nums[right];
        while(left<right&&nums[left]<=key) left++;
        nums[right]=nums[left];
    }
    nums[left]=key;
    return left;
}
void QuickSort(vector<int>& nums,int left,int right){
    if(left<right){
        int pivot=Partition(nums,left,right);
        QuickSort(nums,left,pivot-1);
        QuickSort(nums,pivot+1,right);
    }
}

int main(){
    vector<int> nums={98,36,-9,0,47,23,1,8,10,7};
    QuickSort(nums,0,nums.size()-1);
}
```

```bash
Original: 98  36  -9  0  47  23   1   8   10   7
------------------------------------------------
Updated:  -9   0   1  7   8  10  23  36   47  98
```

### 代码剖析

快速排序采用了分治法的策略 通过Partition函数将数组分而治之 Partition函数使用左右两端的双指针从两端开始遍历 分别将大于小于key的元素置于key的两侧 直到两个双指针相遇 此时key所填入的位置就是下次数组分治的中心

```bash

                 QuickSort(nums,0,9)->Partition(nums,0,9) key=98 [7,36,-9,0,47,23,1,8,10,98] pivot=9
               /                    \
            QuickSort(nums,0,8)      QuickSort(nums,10,9) ×
                    |
            Partition(nums,0,8) key=7 [1,0,-9,7,47,23,36,8,10|98]   pivot=3                
        /                       \
     QuickSort(nums,0,2) [-9,0,1]       QuickSort(nums,4,8) key=47 [10,23,36,8,47] pivot=8
     /                                         /
    QuickSort(nums,0,1) [-9,0]         QuickSort(nums,4,7) key=10 [8,10,36,23] pivot=5
                                        /
                                    QuickSort(nums,6,7) key=36 [23,36] pivot=7
    每一片数组都排好后 向上返回 最后QuickSort(nums,0,9)完成后 数组有序 [-9,0,1,7,8,10,23,36,47,98]
    /*解析代码的时候 跳过了QuickSort(nums,left,right)中 left=right的情况 */

```

### 性能分析

空间复杂度: 快速排序是递归的 需要一个递归工作栈 最坏情况下(每一次分割的时候pivot的值都在数组边界) 栈的深度为<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mo stretchy="false">)</mo></math> 最好情况下(每次分割都在数组中心) 栈的深度为<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><msub><mi>g</mi><mn>2</mn></msub><mrow><mi>n</mi><mo>+</mo><mn>1</mn></mrow><mo stretchy="false">)</mo></math> 因此平均情况下 空间复杂度<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><mi>l</mi><mi>o</mi><msub><mi>g</mi><mn>2</mn></msub><mrow><mi>n</mi></mrow><mo stretchy="false">)</mo></math>

时间复杂度: 最坏情况下 时间复杂度<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><msup><mi>n</mi><mn>2</mn></msup><mo stretchy="false">)</mo></math> 最理想状态下的时间复杂度<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>O</mi><mo stretchy="false">(</mo><mi>n</mi><mi>l</mi><mi>o</mi><msub><mi>g</mi><mn>2</mn></msub><mi>n</mi><mo stretchy="false">)</mo></math>
快速排序平均情况下的运行时间与其最佳状态下的运行时间很接近 而不是接近其最坏情况的运行时间 所以快速排序是所有内部排序算法中平均性能最优的

稳定性: 快速排序中 元素的相对位置会发生变化 即快速排序是一种不稳定的排序方法