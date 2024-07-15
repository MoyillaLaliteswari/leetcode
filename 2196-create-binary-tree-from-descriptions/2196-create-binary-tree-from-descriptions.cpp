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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int,TreeNode*>mp;
        map<int,bool>checkk;
        for(auto ele : d){
            int parent=ele[0],child=ele[1],left=ele[2];
            TreeNode* parentNode=NULL,*childNode=NULL;
            
            if(mp.find(parent)==mp.end()) parentNode=new TreeNode(parent);
            else parentNode=mp[parent];
             
            
            if(mp.find(child)==mp.end()) childNode=new TreeNode(child);
            else childNode=mp[child];
             
            if(left==1) parentNode->left=childNode;
            else    parentNode->right=childNode;
            
            checkk[child]=true;
            mp[parent]=parentNode;
            mp[child]=childNode;
        }
        TreeNode* root=NULL;
        for(auto& [nodeVal,node]:mp){
            if(!checkk[nodeVal]) root=node;
        }
        return root;
        
    }
};