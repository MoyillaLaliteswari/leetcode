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
    void traverse(TreeNode* root,int t,vector<int>&v,int Sum,vector<vector<int>>&ans){
        if(root==NULL)return;
        v.push_back(root->val);
        Sum+=root->val; 
        
        if((Sum==t)and(root->left==NULL && root->right==NULL)){
            ans.push_back(v);
            
        }
        traverse(root->left,t,v,Sum,ans);
        
        traverse(root->right,t,v,Sum,ans);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int>v;
        vector<vector<int>>ans;
        traverse(root,t,v,0,ans);
        return ans;
    }
};