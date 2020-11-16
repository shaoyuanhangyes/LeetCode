#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
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
    Node* inorderSuccessor(Node* node) {
        if(node->right){
            node=node->right;
            while(node->left) node=node->left;
            return node;
        }
        while(node->parent&&node==node->parent->right) node=node->parent;
        return node->parent;
    }
};

int main(){
    vector<int> nums={4,2,5,1,3};
    Node* root=createTree(nums,nums.size(),0);
    Solution ans;
    root=ans.treeToDoublyList(root);
}