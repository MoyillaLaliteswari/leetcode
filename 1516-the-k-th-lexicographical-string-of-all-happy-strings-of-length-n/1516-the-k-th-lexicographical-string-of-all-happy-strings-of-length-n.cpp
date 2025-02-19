class Solution {
public:
    int num;
    string dfs(string prefix,int n,int k){
        if(n==0) return prefix;
        for(char c='a';c<='c';c++){
            if(!prefix.empty() and c==prefix.back()) continue;
            int cnt=(1<<(num-prefix.length()-1));
            if (cnt>=k) return dfs(prefix+c,n-1,k);
            else k-=cnt;
        }
        return "";
    }
    string getHappyString(int n, int k) {
        num=n;
        return dfs("",n,k);
    }
};