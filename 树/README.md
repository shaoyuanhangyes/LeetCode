## LeetCode 二叉树

二叉树刷题C++模版

```C++

/*二叉树结构体*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

```
### 创建二叉树

因为二叉树是非线性结构 不易于直接表示 因此采取顺序存储的思想 按照数组的序号对这个数组以层序遍历的方式创建二叉树

```C++

TreeNode* createTree(const vector<int> &nums,int len,int index){
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){//值为null和位置不合法时直接返回空节点
        root = new TreeNode(nums[index]);
        root->left = createTree(nums,len,2*index+1);
        root->right= createTree(nums,len,2*index+2);
    }
    return root;
}
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8,-1,10};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=createTree(nums,len,0);
    return 0;
}

```

创建后的二叉树为

```C++

        0
      /   \
    1       2
   / \     / \
  3   4   5   6
 / \   \
7   8   10

```
### 二叉树的遍历们

#### 前序遍历

前序遍历(先序遍历) 遍历的次序为 `根 左 右` 

```C++

        0
      /   \
    1       2
   / \     / \
  3   4   5   6
 / \   \
7   8   10      为例子

前序遍历的序列为 [0 1 3 7 8 4 10 2 5 6]

```

前序遍历序列的第一个结点一定是二叉树的根结点

##### 前序遍历递归代码
```C++

vector<int> res;//必须是全局变量的数组
vector<int> preorderTraversal(TreeNode* root) {
    if(root!=NULL){
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return res;
}
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8,-1,10};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=createTree(nums,len,0);
    cout<<"先序遍历的序列为:"<<endl
    vector<int> preOrder=preOrderTraversal(root);
    for(auto x:preOrder) cout<<x<<" ";
    return 0;
}

```

##### 前序遍历迭代代码
```C++

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode* > st;
	TreeNode* node=root;
	while(!st.empty()||node){
	    while(node){
	        st.push(node);
	        res.push_back(node->val);
	        node=node->left;
	    }
	    node=st.top();
	    st.pop();
	    node=node->right;
	}
	return res;
}
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8,-1,10};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=createTree(nums,len,0);
    cout<<"先序遍历的序列为:"<<endl
    vector<int> preOrder=preOrderTraversal(root);
    for(auto x:preOrder) cout<<x<<" ";
    return 0;
}

```

#### 中序遍历 

中序遍历 遍历的次序为 `左 根 右` 

```C++

        0
      /   \
    1       2
   / \     / \
  3   4   5   6
 / \   \
7   8   10      为例子

中序遍历的序列为 [7 3 8 1 4 10 0 5 2 6]

```

通过前序遍历确定了二叉树的根结点后 在中序遍历序列中 根结点的左半部分都是根结点的左子树 根结点的右半部分都是根结点的右子树
BST 二叉搜索树 又名二叉排序树 二叉查找树 的中序序列一定是按从小到大的顺序排列的

##### 中序遍历递归代码

```C++

vector<int> res;//必须是全局变量的数组
vector<int> inorderTraversal(TreeNode* root) {
    if(root!=NULL){
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
    return res;
}

/*以下的主函数不赘述了*/

```

##### 中序遍历迭代代码

```C++

vector<int> inorderTraversal(TreeNode* root) {//迭代算法
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *node=root;
    while(!st.empty()||node){
        while(node){
            st.push(node);
            node=node->left;
        }
        node=st.top();
        st.pop();
        res.push_back(node->val);
        node=node->right;
    }
    return res;
}

```

#### 后序遍历

后序遍历 遍历的次序为 `左 右 根`

```C++

        0
      /   \
    1       2
   / \     / \
  3   4   5   6
 / \   \
7   8   10      为例子

后序遍历的序列为 [7 8 3 10 4 1 5 6 2 0]

```

后序遍历序列的最后一个结点一定是根结点

##### 后序遍历递归代码

```C++

vector<int> res;
vector<int> postorderTraversal(TreeNode* root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
    }
    return res;
}

```

##### 后序遍历迭代代码

第一种解法 标记位

prev记录已经输出到res数组中的上一个结点 防止出现某一结点有右孩子 右孩子输出后 根据栈回到右孩子的父结点 然后又判断是否有右孩子的死循环 当判断到node->right==prev成立 即父结点的右孩子上一次被访问过 就输出这个父结点

```C++

vector<int> postorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode* > st;
    TreeNode* node=root;
    TreeNode* prev=NULL;
    while(!st.empty()||node){
        while(node){
            st.push(node);
            node=node->left;
        }
        node=st.top();
        if(node->right==NULL||node->right==prev){
            res.push_back(node->val);
            st.pop();
            prev=node;
            node=NULL;
        }
        else node=node->right;
    }
    return res;
}

```

第二种解法 反转

根据前序遍历的思想 将遍历序列规则转换为 `根 右 左` 序列输出到数组后 将整个数组反转过来 就变成了`左 右 根`

```C++

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode* > st;
	TreeNode* node=root;
	while(!st.empty()||node){
	    while(node){
	        st.push(node);
	        res.push_back(node->val);//根
	        node=node->right;//右
	    }
	    node=st.top();
	    st.pop();
	    node=node->left;//左
	}
	reverse(res.begin(),res.end());//#include <algorithm>
	return res;
}

```

#### 层序遍历 

层序遍历 每一层元素 按从左到右的顺序逐层输出 

```C++
        0
      /   \
    1       2
   / \     / \
  3   4   5   6
 / \   \
7   8   10      为例子

层序遍历的序列为 [0 1 2 3 4 5 6 7 8 10]

```

##### 层序遍历迭代算法

利用队列进行迭代 返回二维数组 

```C++

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode* > Tree;
    Tree.push(root);
    while(!Tree.empty()){
        vector<int> temp;
        int len=Tree.size();
        while(len--){
            TreeNode *pNode=Tree.front();
            Tree.pop();
            temp.push_back(pNode->val);
            if(pNode->left) Tree.push(pNode->left);
            if(pNode->right) Tree.push(pNode->right);
        }
        res.push_back(temp);
    }
    return res;
}

```

打印二维数组的方法

```C++

void PrintMartrix(vector<vector<int>>& res){
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}

```