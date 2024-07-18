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
    int count;
    
    unordered_map<int, int> dfs(TreeNode* node, int& dis) {
        if (node == NULL) return {};
        unordered_map<int, int> mp;
        mp[1] = 1;
        if (node->left == NULL && node->right == NULL) return mp;
        
        unordered_map<int, int> lh = dfs(node->left, dis);
        unordered_map<int, int> rh = dfs(node->right, dis);
        
        for (auto [lv, lf] : lh) {
            for (auto [rv, rf] : rh) {
                if (lv + rv <= dis) count += (lf * rf);
            }
        }
        
        unordered_map<int, int> parentv;
        for (auto [lv, lf] : lh) {
            if (lv + 1 <= dis) {
                parentv[lv + 1] += lf;
            }
        }
        for (auto [rv, rf] : rh) {
            if (rv + 1 <= dis) {
                parentv[rv + 1] += rf;
            }
        }
        
        return parentv;
    }
    
    int countPairs(TreeNode* root, int distance) {
        count = 0;
        dfs(root, distance);
        return count;
    }
};
