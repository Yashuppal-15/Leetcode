class Solution {
public :

    int kthSmallest ( TreeNode* root , int & k ) {

        // Base case
        if ( root == NULL ) {
            return -1 ;
        }

        // Inorder (LNR)
        // L
        int leftAns = kthSmallest ( root -> left , k ) ;
        if ( leftAns != -1 ) {
            return leftAns ;
        }

        // N
        k -- ;
        if ( k == 0 ) {
            return root -> val ;
        }

        // R
        int rightAns = kthSmallest ( root -> right , k ) ;
        return rightAns ;
    }
};
