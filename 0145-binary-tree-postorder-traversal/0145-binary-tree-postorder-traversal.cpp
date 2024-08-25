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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur=root;
        vector<int>v;
        if(cur==NULL) return v;
        stack<TreeNode*>st;
        st.push(cur);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            if (temp->left != NULL) {
                st.push(temp->left);
                temp->left = NULL;  
            } else if (temp->right != NULL) {
                st.push(temp->right);
                temp->right = NULL; 
            } else {
                v.push_back(temp->val);
                st.pop();
            }
        }
        return v;
    }
};