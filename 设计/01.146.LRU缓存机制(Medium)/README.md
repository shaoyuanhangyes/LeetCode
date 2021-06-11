# 1(146) LRU缓存机制

## 描述

运用你所掌握的数据结构 设计和实现一个LRU (最近最少使用)缓存机制 

实现`LRUCache`类

```bash
LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
```

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？


## 示例

```bash
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

```

提示：

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
最多调用 3 * 104 次 get 和 put

## Description

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

```bash
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
```

The functions get and put must each run in O(1) average time complexity.


## Example


```bash
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

```

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.


## 解题

设计之前 先让我们复习一下什么是LRU  `Least Recently Used` 最近最少使用 是常见的页面置换算法 算法思路用一句话概括就是当发生缺页中断的时候 选择未使用时间最长的页面进行置换


如何判断最少使用呢 可以抽象成一个双向链表 靠近链表头部的为最近访问/添加过的 靠近链表尾部的为最长时间未访问/添加过的 通过添加 移动 删除等一系列操作 来实现判断

同时若要达成O(1)的时间复杂度 需要用到哈希表来存储数据 

因此 实现LRU缓存机制 就需要使用到哈希链表这一数据结构组合

首先实现一个双向链表

```C++
//结构体为
struct DList {
    int key;
    int val;
    DList* prev;
    DList* next;
    DList() : key(0), val(0), prev(nullptr), next(nullptr){}
    DList(int x,int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
};
```

因为双向链表中 最近访问过的要靠近链表的头结点 所以新结点需要插入到`head`的后面

```C++
void InsertHead(DList* node) {
    node->next = head->next;
    head->next->prev = node;
    node->prev = head;
    head->next = node;
}
```

双向链表中 删除某一结点

```C++
void DeleteNode(DList* node) {
	node->prev->next = node->next;
    node->next->prev = node->prev;
}
```

因为访问过的结点需要移动到头结点的后面 因此 借助上面的插入和删除两个函数来实现移动 将要移动的结点先从链表中删除 然后再插入到头结点之后

```C++
void MoveToHead(DList* node){
    DeleteNode(node);
    InsertHead(node);
}
```

当插入的结点数超过了规定的缓冲区容量 就需要对最久未被访问过的结点进行删除操作 自然要删除的是尾结点之前的那个结点

```C++
DList* EraseTail(){
    DList* node = tail->prev;
    DeleteNode(node);
    return node;
}
```

双向链表的基本操作已经构建完成 现在需要构建LRU的功能函数

LRUCache的私有成员有

```C++
private:
    int size; //人为规定的缓冲区最大容量
    int quantity; //双向链表中的结点数量
    DList* head; //头结点 
    DList* tail; //尾结点
    unordered_map<int ,DList*> p; //哈希映射 
```

LRUCache的构造函数 初始化`size` `quantity` 构建一个容量为空的双向链表

```C++
LRUCache(int capacity) {
    this->size = capacity;
    this->quantity = 0;
    head = new DList();
    tail = new DList();
    head->next = tail;
    tail->prev = head;
}
```

get函数 构建之前 需要分类讨论一下可能遇到的情况 
当get函数无法找到key值对应的数据时 就会返回-1 
当get函数可以找到key值对应的数据时 会将这个k-v移动到head之后 即最近访问过 然后将这个key值对应的数据return给调用者

```C++
int get(int key) {
    if(!p.count(key)){ //map的count() 命中了返回1 未命中返回0
        return -1;
    }
    DList* node = p[key];
    MoveToHead(node);
    return node->val;
}
```
put函数 构建之前 需要分类讨论一下可能遇到的情况 
当put函数插入的k-v 在哈希映射中找不到对应的key 即要插入的val为新数据 所以需要将k-v插入到head之后 并且需要判断是否超出了缓冲区的最大容量 若超出 则需要将双向链表的最后一个有效结点删除掉
当put函数插入的k-v可以在哈希映射中找到对应的key 即要插入的val是更新已有的k-v 所以只需要找到对应key 修改val即可

```C++
void put(int key, int value) {
    if(!p.count(key)){
        DList* node = new DList(key,value);
        p[key] = node;
        InsertHead(node);
        ++quantity;
        if(quantity > size){
        	DList* temp = EraseTail();
            p.erase(temp->key);
            delete temp;
            --quantity;
    	}
    }
    else{
        DList* node = p[key];
        node->val = value;
        MoveToHead(node);
    }
}
```


### 完整代码

```C++

#include <unordered_map>

struct DList {
    int key;
    int val;
    DList* prev;
    DList* next;
    DList() : key(0), val(0), prev(nullptr), next(nullptr){}
    DList(int x,int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int size;
    int quantity;
    DList* head;
    DList* tail;
    unordered_map<int ,DList*> p;
    
public:
    LRUCache(int capacity) {
        this->size = capacity;
        this->quantity = 0;
        head = new DList();
        tail = new DList();
        head->next = tail;
        tail->prev = head;
    }
    void InsertHead(DList* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    void DeleteNode(DList* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void MoveToHead(DList* node){
        DeleteNode(node);
        InsertHead(node);
    }
    DList* EraseTail(){
        DList* node = tail->prev;
        DeleteNode(node);
        return node;
    }
    int get(int key) {
        if(!p.count(key)){
            return -1;
        }
        DList* node = p[key];
        MoveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if(!p.count(key)){
            DList* node = new DList(key,value);
            p[key] = node;
            InsertHead(node);
            ++quantity;
            if(quantity > size){
                DList* temp = EraseTail();
                p.erase(temp->key);
                delete temp;
                --quantity;
            }
        }
        else{
            DList* node = p[key];
            node->val = value;
            MoveToHead(node);
        }
    }
};
```