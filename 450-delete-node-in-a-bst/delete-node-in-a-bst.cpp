class Solution {
public :

    TreeNode* deleteNode (TreeNode* root, int key) {

        // Base case
        if (root == NULL)
            return NULL;

        // 1 case hum solve kar lenge
        if (root -> val == key) {

            // Target root par hi ho sakta hai

            // case 1 :
            if (root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            }

            // case 2 :
            else if (root -> left == NULL && root -> right != NULL) {
                auto temp = root;
                root = temp -> right;
                delete temp;
                return root;
            }

            // case 3 :
            else if (root -> left != NULL && root -> right == NULL) {
                auto temp = root;
                root = temp -> left;
                delete temp;
                return root;
            }

            // case 4 :
            else {

                // BST MAX Node find karlo
                auto lscan = root -> left;
                while (lscan -> right) {
                    lscan = lscan -> right;
                }

                lscan -> right = root -> right;
                auto temp = root;
                root = temp -> left;
                delete temp;
                return root;
            }
        }

        // Ab recursion solve kar lega
        else if (root -> val < key) {
            root -> right = deleteNode (root -> right, key);      // root ke right me check karo
        }
        else {
            root -> left = deleteNode (root -> left, key);        // root ke left me check karo
        }

        return root;
    }
};
