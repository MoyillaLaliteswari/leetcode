/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void reve(TreeNode* lnode,TreeNode* rnode,int level){
            if(!lnode || !rnode) return;
            if(level%2==1){
                swap(lnode->val,rnode->val);
            }
            reve(lnode->left,rnode->right,level+1);
            reve(lnode->right,rnode->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        reve(root->left,root->right,1);
        return root;
    }
};