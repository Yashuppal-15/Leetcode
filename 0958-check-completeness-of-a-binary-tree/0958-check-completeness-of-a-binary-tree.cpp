class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        // Initially
        q.push(root);
        bool nullFound = false;

        // Ab queue par traverse kar rahe hai
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {
                nullFound = true;
            }
            else {
                if (nullFound == true) {
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        // Agar yaha tak pahuch gya hu to
        // CBT tree hai
        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
// Where N is number of nodes in binary tree
