class Solution {
public :

    void storeInorder ( TreeNode* root , vector < int > & inorder ) {

        // Base case
        if ( root == NULL ) {
            return ;
        }

        // Inorder (LNR)
        // L
        storeInorder ( root -> left , inorder ) ;

        // N
        inorder . push_back ( root -> val ) ;

        // R
        storeInorder ( root -> right , inorder ) ;
    }

    bool findTarget ( TreeNode* root , int k ) {

        // step1 : inorder array
        vector < int > inorder ;
        storeInorder ( root , inorder ) ;

        // step2 : find target sum is or not
        int s = 0 ;
        int e = inorder . size ( ) - 1 ;

        while ( s < e ) {

            int sum = inorder [ s ] + inorder [ e ] ;
            if ( sum == k ) {
                return true ;
            }

            else if ( sum < k ) {
                s ++ ;
            }

            else if ( sum > k ) {
                e -- ;
            }
        }

        return false ;
    }
};
