class Solution {
public:

    string smallestNumber(string pattern) {
        int n=pattern.size();
        string res="";
        int v[n+1];
        int index=0;
        for(int i=0;i<=n;i++){
            v[index++]=i+1;
            if(i==n || pattern[i]=='I'){
                while(index>0){
                    res+=to_string(v[--index]);
                }
            }
        }
        return res;
    }
};