class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int big = x > y ? x : y;
        int small = big == x ? y : x;
        char first = big == x ? 'a' : 'b';
        char second = first == 'a' ? 'b' : 'a';
        int sum = 0;
        stack<char> st1;

        // First pass
        for (char c : s) {
            if (c == second && !st1.empty() && st1.top() == first) {
                st1.pop();
                sum += big;
            } else {
                st1.push(c);
            }
        }

        // Second pass
        stack<char> st2;
        while (!st1.empty()) {
            char c = st1.top();
            st1.pop();
            if (c == second && !st2.empty() && st2.top() == first) {
                st2.pop();
                sum += small;
            } else {
                st2.push(c);
            }
        }

        return sum;
    }
};
