
#include <iostream>
#include <unordered_map>

using namespace std;

struct DList {
    int key;
    int val;
    DList* prev;
    DList* next;
    int freq;
    DList() : key(0), val(0), prev(nullptr), next(nullptr){}
    DList(int x,int y) : key(x), val(y), prev(nullptr), next(nullptr), freq(1){}
};

struct FreqList {
    int freq;
    DList* head;
    DList* tail;
    FreqList(int x) : freq(x), head(new DList()), tail(new DList()) {
        head->next = tail;
        tail->prev = head;
    }
};

class LFUCache {
private:
    int size;
    int min_cnt;
    unordered_map<int, DList*> p;
    unordered_map<int,FreqList*> fp;
public:
    LFUCache(int capacity) {
        this->size = capacity;
    }

    bool emptyFList(FreqList* list){
        return list->head->next == list->tail;
    }

    void InsertHead(DList* node) {
        int freq = node->freq;
        if(!fp.count(freq)){
            fp[freq] = new FreqList(freq);
        }
        FreqList* temp = fp[freq];
        node->next = temp->head->next;
        temp->head->next->prev = node;
        node->prev = temp->head;
        temp->head->next = node;
    }


    //不用修改
    void DeleteNode(DList* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

//    void MoveToHead(DList* node){
//        DeleteNode(node);
//        InsertHead(node);
//    }

    DList* EraseTail(){
        DList* node = fp[min_cnt]->tail->prev;
        DeleteNode(node);
        return node;
    }

    int get(int key) {
        int res= -1;
        if(!p.count(key)){
            return res;
        }
        DList* node = p[key];
        node->freq++;
        res = node->val;
        DeleteNode(node);
        if(emptyFList(fp[min_cnt])) min_cnt++;
        InsertHead(node);
        return res;
    }

    void put(int key, int value) {
        if(size==0) return;
        if(get(key) != -1){
            p[key]->val = value;
        }
        else{
            if(p.size() == size){
                DList* temp = EraseTail();
                p.erase(temp->key);
//                delete temp;
            }
            DList* node = new DList(key,value);
            p[key] = node;
            min_cnt = 1;
            InsertHead(node);
        }
    }
};




int main(){
//    LFUCache* lFuCache = new LFUCache(3);
//    cout<<"null"<<" ";
//    lFuCache->put(2, 2); // 缓存是 2
//    cout<<"null"<<" ";
//    lFuCache->put(1, 1); // 缓存是 1 2
//    cout<<"null"<<" ";
//    cout << lFuCache->get(2) << " "; //2 1
//    cout << lFuCache->get(1) << " "; //1 2
//    cout << lFuCache->get(2) << " ";// 2 1
//    lFuCache->put(3, 3); // 2 1 3
//    cout<<"null"<<" ";
//    lFuCache->put(4, 4); // 4 2 1
//    cout<<"null"<<" ";
//    cout << lFuCache->get(3) << " ";    // 返回 -1 (未找到)
//    cout << lFuCache->get(2) << " ";    // 返回 2
//    cout << lFuCache->get(1) << " ";    // 返回 1
//    cout << lFuCache->get(4) << " ";    // 返回 4
    LFUCache* lFuCache = new LFUCache(1);
    cout<<"null"<<" ";
    lFuCache->put(2, 1);
    cout<<"null"<<" ";
    cout << lFuCache->get(2) << " ";
    lFuCache->put(3, 2);
    cout<<"null"<<" ";
    cout << lFuCache->get(2) << " ";
    cout << lFuCache->get(3) << " ";
}