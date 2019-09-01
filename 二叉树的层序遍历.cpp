从上往下打印出二叉树的每个节点，同层节点从左至右打印。
思想 借用队列的先进先出 保存同级右边节点指针

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/  

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q; 
        q.push(root);
       while(!q.empty())
        { 
            root=q.front();
            q.pop();
            if(root)
            {
            v.push_back(root->val);
            q.push(root->left);
            q.push(root->right);
            }
           else continue;//这句可以不要  ，即当前节点为空时 什么都不做
        }
        return v;
    }
   
};