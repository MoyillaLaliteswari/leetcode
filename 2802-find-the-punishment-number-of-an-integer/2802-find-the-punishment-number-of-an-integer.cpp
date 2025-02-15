class Solution {
public:
    bool rec(int n,int tar){
        if(n==tar) return 1;
        if(n==0) return tar=0;
        for(int m=10;m<=n;m*=10){
            if(rec(n/m,tar-n%m)) return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int s=0;
        for(int i=1;i<=n;i++){
            if(i%9!=0 and i%9!=1)
                continue;
            const int x=i*i;
            s+=(rec(x,i))?x:0;
        }
        return s;
    }
};