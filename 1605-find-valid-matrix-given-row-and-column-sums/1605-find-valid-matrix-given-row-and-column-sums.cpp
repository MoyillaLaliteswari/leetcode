class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> v(numRows, vector<int>(numCols, 0));

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                v[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= v[i][j];
                colSum[j] -= v[i][j];
            }
        }
        return v;
    }
};
