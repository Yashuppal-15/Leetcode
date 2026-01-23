class Solution {
public :

    TreeNode* lowestCommonAncestor ( TreeNode* root , TreeNode* p , TreeNode* q ) {

        // Base case
        if ( root == NULL ) {
            return NULL ;
        }

        // case 1 : p is in left subtree & q is in right subtree of root Node
        if ( p -> val < root -> val && q -> val > root -> val ) {
            return root ;
        }

        // case 2 : q is in left subtree & p is in right subtree
        else if ( p -> val > root -> val && q -> val < root -> val ) {
            return root ;
        }

        // case 3 : p and q are in left subtree of root Node
        else if ( p -> val < root -> val && q -> val < root -> val ) {
            TreeNode* leftAns = lowestCommonAncestor ( root -> left , p , q ) ;
            return leftAns ;
        }

        // case 4 : p and q are in right subtree of root Node
        else if ( p -> val > root -> val && q -> val > root -> val ) {
            TreeNode* rightAns = lowestCommonAncestor ( root -> right , p , q ) ;
            return rightAns ;
        }

        return root ;   // case 5 , 6
    }
};
