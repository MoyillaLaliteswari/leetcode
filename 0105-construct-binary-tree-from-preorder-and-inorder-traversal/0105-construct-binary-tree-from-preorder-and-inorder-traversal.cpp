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
    TreeNode* constructt(vector<int>&preorder,int ps,int pe,
                       vector<int>&inorder,int ins,int ine,map<int,int>&mp){
        if(ps>pe || ins>ine) return NULL;
     TreeNode* root=new TreeNode(preorder[ps]);
     int inroot=mp[root->val];
     int numsleft=inroot-ins;
    root->left=constructt(preorder,ps+1,ps+numsleft,
                        inorder,ins,inroot-1,mp);
    root->right=constructt(preorder,ps+numsleft+1,pe,
                         inorder,inroot+1,ine,mp);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
	int n=inorder.size()-1;
        int ps=0,pe=n;
        int ins=0,ine=n;
        
        for(int i=0;i<=n;i++){
            mp[inorder[i]]=i;
        }
        return constructt(preorder,0,n,inorder,ins,ine,mp);      
        
    }
};