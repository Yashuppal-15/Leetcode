class Solution {
private:
    int max_from_row_and_col(int col, int row, vector<vector<int>>& grid)  {
        int m = grid.size();
        int n = grid[0].size();
        int max_col = 0, max_row = 0;
        for (int i = 0; i < n; i++) {
            max_col = max(grid[row][i], max_col);
        }

        for (int i = 0; i < m; i++) {
            max_row = max(grid[i][col], max_row);
        }

        return min(max_col, max_row);
    }

public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int og = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += max_from_row_and_col(j, i, grid);
                og += grid[i][j];
            }
        }
        return ans - og;
    }
};