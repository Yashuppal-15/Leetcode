class Solution {
public:

    bool solve(TreeNode* root, int targetSum, int sum)
    {
        // Base case
        if (root == NULL)
        {
            return false;
        }

        // 1 case hum solve Kar lenge
        sum += root->val;

        if (root->left == NULL && root->right == NULL)   // check kro -> current root node leaf node par to nhi hai
        {
            // verify
            if (targetSum == sum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Ab recursion solve kr lega
        bool leftSub = solve(root->left, targetSum, sum);
        bool rightSub = solve(root->right, targetSum, sum);

        return leftSub || rightSub;              // Yeh important line hai -> return kaise karna hai
    }

    bool hasPathSum(TreeNode* root, int targetSum)
    {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};
