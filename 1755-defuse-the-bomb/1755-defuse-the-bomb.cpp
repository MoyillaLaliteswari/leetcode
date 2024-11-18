class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> v(n, 0);

        if (k == 0) {
            
            return v;
        }

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            if (k > 0) {
                // Sum next k elements in circular array
                for (int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
            } else {
                // Sum previous |k| elements in circular array
                for (int j = 1; j <= -k; ++j) {
                    sum += code[(i - j + n) % n];
                }
            }
            v[i] = sum;
        }

        return v;
    }
};
