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
    string s;
    int idx=0,lvl=0,level=0;
    void help(TreeNode*parent,int lvl){
        while(idx<s.size() and lvl==level){
            int num=0;
            while(idx<s.size() and isdigit(s[idx])){
                num=num*10+(s[idx++]-'0');
            }
            TreeNode* node=new TreeNode(num);
            if(!parent->left){
                parent->left=node;
            }
            else{
                parent->right=node;
            }
            level=0;
            while(idx<s.size() and s[idx]=='-'){
                level++;
                idx++;
            }
            help(node,lvl+1);
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        // if(traversal.size()==0) return NULL;
        s=traversal;
        TreeNode*node=new TreeNode(-1);
        help(node,0);
        return node->left;
    }
};