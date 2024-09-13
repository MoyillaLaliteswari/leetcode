class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        
        vector<int> prefixXor(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
      
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            result.push_back(prefixXor[right + 1] ^ prefixXor[left]);
        }
        
        return result;
    }
};
