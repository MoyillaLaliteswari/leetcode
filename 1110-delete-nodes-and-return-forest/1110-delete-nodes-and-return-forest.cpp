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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        if (!root) return {};
        
        delNodesHelper(root, to_delete_set, result, true);
        
        return result;
    }
    
    TreeNode* delNodesHelper(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& result, bool is_root) {
        if (!node) return nullptr;
        
        bool to_delete = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !to_delete) {
            result.push_back(node);
        }
        
        node->left = delNodesHelper(node->left, to_delete_set, result, to_delete);
        node->right = delNodesHelper(node->right, to_delete_set, result, to_delete);
        
        return to_delete ? nullptr : node;
    }
};
