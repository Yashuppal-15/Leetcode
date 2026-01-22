class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case.
        if (root == NULL) {
            return 0;
        }

        int leftNode  = maxDepth(root->left);
        int rightNode = maxDepth(root->right);

        int height = max(leftNode, rightNode) + 1;
        return height;
    }
};
