#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* createList(vector<int> &nums){
    ListNode* prev=new ListNode(nums[0]);
    ListNode* prevHead=prev;
    for(int i=1;i<nums.size();++i){
        ListNode* temp=new ListNode(nums[i]);
        temp->next=prev->next;
        prev->next=temp;
        prev=temp;
    }
    return prevHead;
}

void ShowList(ListNode* L){
    while(L){
        cout<<L->val<<" ";
        L=L->next;
    }
}
class Solution{
public:
    void makeHeap(int* a,int len,int* b){
        for(int i=(len-1)/2;i>=0;i--){
            adjustHeap(a,i,len,b);
        }
    }

    void adjustHeap(int*a,int i,int len,int* b){
        int left=2*i+1;
        int right=2*i+2;
        int minNum=i;
        if(left<=len&&a[left]<a[minNum]) minNum=left;
        if(right<=len&&a[right]<a[minNum]) minNum=right;
        if(minNum!=i){
            swap(a[i],a[minNum]);
            swap(b[i],b[minNum]);
            adjustHeap(a,minNum,len,b);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        vector<ListNode*> list;
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        int n=lists.size();
        if(n==0) return head->next;
        for(int i=0;i<n;++i){
            if(lists[i]!=NULL) list.push_back(lists[i]);
        }
        n=list.size();
        if(n==0) return head->next;
        int a[n],b[n];
        for(int i=0;i<n;++i){
            a[i]=list[i]->val;b[i]=i;
        }
        makeHeap(a,n-1,b);
        int len=n-1;
        while(len>=0){
            ListNode* node=new ListNode(a[0]);
            temp->next=node;
            temp=node;
            if(list[b[0]]->next!=NULL){
                list[b[0]]=list[b[0]]->next;
                a[0]=list[b[0]]->val;
                adjustHeap(a,0,len,b);
            }
            else{
                swap(a[0],a[len]);
                swap(b[0],b[len]);
                len--;
                adjustHeap(a,0,len,b);
            }
        }
        return head->next;
    }
};
int main(){
    vector<int> nums1={1,4,5};
    vector<int> nums2={1,3,4};
    vector<int> nums3={2,6};
    ListNode* L1=createList(nums1);
    ListNode* L2=createList(nums2);
    ListNode* L3=createList(nums3);
    vector<ListNode*> L;
    L.push_back(L1);L.push_back(L2);L.push_back(L3);
    Solution answer;
    ListNode* res=answer.mergeKLists(L);
    ShowList(res);
    return 0;
}
