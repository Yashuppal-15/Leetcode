class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int row = mat.size();          // number of rows
        int col = mat[0].size();       // number of columns

        int maxOnes = 0;               // store max count of ones
        int rowIndex = 0;              // store row index

        // Traverse each row
        for(int i = 0; i < row; i++) {
            int count = 0;

            // Count ones in current row
            for(int j = 0; j < col; j++) {
                if(mat[i][j] == 1) {
                    count++;
                }
            }

            // Update max ones and row index
            if(count > maxOnes) {
                maxOnes = count;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};

/*
Time Complexity: O(M * N)
Space Complexity: O(1)
*/
