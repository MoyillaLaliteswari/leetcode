class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>v;
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            v.push_back(word);
        }
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i].substr(0,searchWord.size())==searchWord){
                return i+1;
            }
        }
        return -1;
    }
};