#include<iostream>
#include<vector>

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
	ListNode* MergeList(ListNode* L1,ListNode* L2){
		ListNode* res=new ListNode(-1);
		ListNode* temp=res;
		while(L1&&L2){
			if(L1->val<L2->val){
				temp->next=L1;
				temp=temp->next;
				L1=L1->next;
			}
			else{
				temp->next=L2;
				temp=temp->next;
				L2=L2->next;
			}
		}
		if(!L1) temp->next=L2;
		else temp->next=L1;
		return res->next;
	}
};
int main(){
	vector<int> nums1={1,3,4,6};
	vector<int> nums2={2,5,7};
	ListNode* L1=createList(nums1);
	ListNode* L2=createList(nums2);
	Solution answer;
	ListNode* L3=answer.MergeList(L1,L2);
	ShowList(L3);
	return 0;
}
