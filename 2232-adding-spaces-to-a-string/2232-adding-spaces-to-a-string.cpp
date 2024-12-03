class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int cnt=0;
        int j=0;
        string result;
        for (int i=0;i<s.size();i++){
            if(j<spaces.size() and spaces[j]==i){
                result+=' ';
                j++;
            }
            result+=s[i];
        }
        return result;
    }
};