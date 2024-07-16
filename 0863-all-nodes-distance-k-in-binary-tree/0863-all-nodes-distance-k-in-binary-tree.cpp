/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) {
                mp[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                mp[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        markparents(root, mp, target);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int cur_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (cur_level == k) break;
            
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                
                if (cur->left && !visited[cur->left]) {
                    q.push(cur->left);
                    visited[cur->left] = true;
                }
                if (cur->right && !visited[cur->right]) {
                    q.push(cur->right);
                    visited[cur->right] = true;
                }
                
                TreeNode* parent = mp[cur];
                if (parent && !visited[parent]) {
                    q.push(parent);
                    visited[parent] = true;
                }
            }
            cur_level++;
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};
