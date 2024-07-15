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
    // int height(TreeNode* root){
    //     if(root==NULL) return 0;
    //     int lh=root->left;
    //     int rh=root->right;
    //     return 1+max(lh,rh);
    // }
    
   int minDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
   
    if (root->left == NULL) {
        return 1 + minDepth(root->right);
    }
   
    if (root->right == NULL) {
        return 1 + minDepth(root->left);
    }
    
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return 1 + min(lh, rh);
}
};