#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int data;
    ListNode* link;
    ListNode(int x):data(x),link(NULL){}
};

ListNode* createList(vector<int>& nums){
    ListNode* list=new ListNode(-1);
    ListNode* prev=list;
    for(int i=0;i<nums.size();++i){
        ListNode* node=new ListNode(nums[i]);
        prev->link=node;
        prev=node;
    }
    return list;
}

bool searchKpositon(ListNode* list,int k){
    ListNode* left=list->link;
    ListNode* right=list->link;
    while(--k) right=right->link;
    if(right==NULL) return 0;
    while(right->link!=NULL){
        right=right->link;
        left=left->link;
    }
    cout<<left->data<<endl;
    return 1;
}


int main(){
    vector<int> nums={5,4,3,2,1};
    ListNode* list=createList(nums);
    int k;
    cout<<"k value="<<endl;
    cin>>k;
    cout<<searchKpositon(list,k);
    return 0;
}
