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
    TreeNode* constructt(vector<int>& inorder,int is,int ie,
                        vector<int>& postorder,int ps,int pe,map<int,int>&mp){
        if(is>ie || ps>pe) return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mp[root->val];
        int nums=inroot-is;
        root->left=constructt(inorder,is,inroot-1,
                             postorder,ps,ps+nums-1,mp);
        root->right=constructt(inorder,inroot+1,ie,
                              postorder,ps+nums,pe-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size()-1;
        int ps=0,pe=n;
        int is=0,ie=n;
        map<int,int>mp;
        for(int i=0;i<=n;i++){
            mp[inorder[i]]=i;
        }
        return constructt(inorder,is,ie,postorder,ps,pe,mp);
    }
};