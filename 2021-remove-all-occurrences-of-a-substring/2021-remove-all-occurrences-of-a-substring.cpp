class Solution {
public:
    bool helper(stack<char>&st,string& part,int len){
        stack<char>st1=st;
        for(int i=len-1;i>=0;i--){
            if(st1.top()!=part[i]){
                return false;
            }
            st1.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int len=s.size();
        int plen=part.size();
        for(int i=0;i<len;i++){
            st.push(s[i]);
            if(st.size()>=plen and helper(st,part,plen)){
                for(int j=0;j<plen;j++) st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};