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
    int getMinSwaps(vector<int>&nums){
        int swaps=0;
        vector<int>target=nums;
        sort(target.begin(),target.end());
        unordered_map<int,int>pos;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target[i]){
                swaps++;
                int curPos=pos[target[i]];
                pos[nums[i]]=curPos;
                swap(nums[curPos],nums[i]);
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=0;
        while(!q.empty()){
            int s=q.size();
            vector<int>l(s);
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                l[i]=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res+=getMinSwaps(l);
        }
        return res;
    }
};