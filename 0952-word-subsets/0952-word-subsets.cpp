class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq1[26] = {0};
        int freq2[26];

        for (const auto& word : words2) {
            memset(freq2, 0, sizeof freq2);
            for (char ch : word) {
                freq2[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                freq1[i] = max(freq1[i], freq2[i]);
            }
        }

        vector<string> result;
        for (const auto& word : words1) {
            memset(freq2, 0, sizeof freq2);
            for (char ch : word) {
                freq2[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq1[i] > freq2[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.emplace_back(word);
            }
        }

        return result;
    }
};
