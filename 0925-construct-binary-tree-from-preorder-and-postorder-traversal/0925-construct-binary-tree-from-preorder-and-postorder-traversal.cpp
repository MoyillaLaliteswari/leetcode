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
    TreeNode* helper(int ps,int pe,int pos,vector<int>&preorder,vector<int>&postorder){
        if(ps>pe) return NULL;
        if(ps==pe) return new TreeNode(preorder[ps]);
        int lr=preorder[ps+1];
        int nl=1;
        while(postorder[pos+nl-1]!=lr){
            nl++;
        }
        TreeNode* root=new TreeNode(preorder[ps]);
        root->left=helper(ps+1,ps+nl,pos,preorder,postorder);
        root->right=helper(ps+nl+1,pe,pos+nl,preorder,postorder);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return helper(0,n-1,0,preorder,postorder);
    }
};