class Solution {
public:

    void solve(TreeNode* root, int targetSum, int sum,
               vector<int>& temp, vector<vector<int>>& ans)
    {
        // Base case
        if (root == NULL)
        {
            return;
        }

        // 1 case hum solve Kar lenge
        sum += root->val;
        temp.push_back(root->val);

        // check kro -> current root node leaf node par to nhi hai
        if (root->left == NULL && root->right == NULL)
        {
            // verify
            if (targetSum == sum)
            {
                ans.push_back(temp);
            }
            // ❌ NO return here
        }

        // Ab recursion solve kr lega
        solve(root->left, targetSum, sum, temp, ans);
        solve(root->right, targetSum, sum, temp, ans);

        // 🔥 Backtracking (MOST IMPORTANT)
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;

        solve(root, targetSum, sum, temp, ans);

        return ans;
    }
};
