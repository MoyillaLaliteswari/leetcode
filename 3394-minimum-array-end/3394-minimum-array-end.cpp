class Solution {
public:
    long long minEnd(int n, int x) {
        long long result=x;
        long long rem=n-1;
        long position=1;
        while(rem){
            if(!(x&position)){
                result |= (rem & 1) * position;
                rem >>= 1;
            }
            position <<= 1;
        }
        return result;
    }
};