class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,j=0;
        while(i<str1.size() and j<str2.size()){
            if(str1[i]==str2[j] or str1[i]-'a'+1==str2[j]-'a'){
                // i++;
                j++;
            }
            else if(str1[i]=='z' and str2[j]=='a'){
                // i++;
                j++;
            }
            i++;
        }
        return (j==str2.size());
    }
};