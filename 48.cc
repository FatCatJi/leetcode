class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; ++i) {
            for (int j = i; j < (n-1-i); ++j) {
                int x = i, y = j;
                int tmp = matrix[x][y];
                // (x, y)旋转90度，x行变成倒数x列，y列变成y行，(y, n-1-x)
                for (int k = 0; k < 4; ++k) {
                    swap(x, y);
                    y = n-1-y;
                    swap(tmp, matrix[x][y]);
                }
            }
        }
    }
};
