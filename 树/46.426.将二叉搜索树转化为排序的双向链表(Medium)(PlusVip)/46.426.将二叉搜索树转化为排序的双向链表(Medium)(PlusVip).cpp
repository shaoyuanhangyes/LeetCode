#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node* createTree(vector<int>& nums,int len,int index){
    Node* root=NULL;
    if(index<len&&nums[index]!=-1){
        root=new Node(nums[index]);
        root->left=createTree(nums,len,2*index+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        head=NULL;tail=NULL;
        inorder(root);
        head->left=tail;
        tail->right=head;
        return head;
    }

private:
    Node* head;
    Node* tail;
    void inorder(Node* root){
        if(!root) return ;
        inorder(root->left);

        if(!tail) head=root;
        else{
            tail->right=root;
            root->left=tail;
        }
        tail=root;

        inorder(root->right);
    }
};

int main(){
    vector<int> nums={4,2,5,1,3};
    Node* root=createTree(nums,nums.size(),0);
    Solution ans;
    root=ans.treeToDoublyList(root);
}