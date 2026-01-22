class Solution {
public:

    // ================== Function to find height of Binary Tree ==================
    int height(TreeNode* root) {

        // Base case:
        if (root == NULL) {                          // If tree is empty, height is 0
            return 0;
        }

        int LH = height(root->left);              // Recursive call to find height of left subtree
        int RH = height(root->right);            // Recursive call to find height of right subtree
        int finalHeight = max(LH, RH) + 1;       // Final height = maximum of left & right subtree + 1 (for current node)

        return finalHeight;                          // Return height of current tree
    }


    // ================== Function to find diameter of Binary Tree ==================
    int diameterOfBinaryTree(TreeNode* root) {

        // Base case:
        if (root == NULL) {                                       // If tree is empty, diameter is 0
            return 0;
        }

        // Option 1: Diameter lies completely in left subtree
        int option1 = diameterOfBinaryTree(root->left);

        // Option 2: Diameter lies completely in right subtree
        int option2 = diameterOfBinaryTree(root->right);

        // Option 3: Diameter passes through the root
        int option3 = height(root->left) + height(root->right);     // (height of left subtree + height of right subtree)

        int diameter = max(option1, max(option2, option3));         // Final diameter is maximum of all three options

        return diameter;                                            // Return diameter
    }
};
