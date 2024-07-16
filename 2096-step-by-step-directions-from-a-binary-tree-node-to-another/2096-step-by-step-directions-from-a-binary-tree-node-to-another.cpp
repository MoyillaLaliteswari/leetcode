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
    bool direction(TreeNode* root, int s, string& str) {
        if (root == NULL) {
            return false;
        }
        if (root->val == s) {
            return true;
        }
        
        str.push_back('L');
        if (direction(root->left, s, str)) {
            return true;
        }
        str.pop_back();
        
        str.push_back('R');
        if (direction(root->right, s, str)) {
            return true;
        }
        str.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string spath, dpath;
        direction(root, startValue, spath);
        direction(root, destValue, dpath);
        
     
        int i = 0;
        while (i < spath.size() && i < dpath.size() && spath[i] == dpath[i]) {
            i++;
        }
        
        
        string result(spath.size() - i, 'U');
        result += dpath.substr(i);
        
        return result;
    }
};
