class Solution {
public:
    int passThePillow(int n, int time) {
        if (time < n) {
            return time + 1;
        }
        
        
        int k = time / (n - 1);
        int r = time % (n - 1);

        
        if (k % 2 == 0) {
            return r + 1;
        } else {
            return n - r;
        }
    }
};
