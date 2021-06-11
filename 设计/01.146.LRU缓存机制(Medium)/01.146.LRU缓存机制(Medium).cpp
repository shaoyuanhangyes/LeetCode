
#include <iostream>
#include <unordered_map>

using namespace std;

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
int main(){
    LRUCache* lRUCache = new LRUCache(2);
    cout<<"null"<<" ";
    lRUCache->put(1, 1); // 缓存是 {1=1}
    cout<<"null"<<" ";
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout<<"null"<<" ";
    cout<<lRUCache->get(1)<<" ";    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout<<"null"<<" ";
    cout<<lRUCache->get(2)<<" ";    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout<<"null"<<" ";
    cout<<lRUCache->get(1)<<" ";    // 返回 -1 (未找到)
    cout<<lRUCache->get(3)<<" ";    // 返回 3
    cout<<lRUCache->get(4)<<" ";    // 返回 4
}