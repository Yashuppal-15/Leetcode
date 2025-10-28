class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);        //→ Create a 2D vector to hold all rows of Pascal’s triangle.

        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1); // Each row has (i+1) elements
            ans[i][0] = ans[i][i] = 1; // First and last elements are always 1

            // Fill the middle elements
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        return ans;
    }
};
