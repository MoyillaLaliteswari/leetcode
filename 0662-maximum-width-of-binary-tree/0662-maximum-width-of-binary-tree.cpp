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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            unsigned long long mini=q.front().second;
            unsigned long long first,last;
            for(int i=0;i<size;i++){
                unsigned long long cur=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur;
                if(i==size-1) last=cur;
                if(node->left) q.push({node->left,cur*2+1});
                if(node->right) q.push({node->right,cur*2+2});
                
            }
            ans=max(ans,int(last-first+1));
        }
        return ans;
    }
};