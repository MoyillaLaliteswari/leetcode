class Solution {
public:
    int minimumPushes(string word) {
        
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

       
        vector<int> frequencies;
        for (const auto& pair : freq) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());  

        int result = 0;
        int pushCount = 1;  
        int charactersInCurrentKey = 0;  
        for (int freq : frequencies) {
            charactersInCurrentKey++;
            result += freq * pushCount;
            if (charactersInCurrentKey % 8 == 0) {
                pushCount++;
            }
        }

        return result;
    }
};
