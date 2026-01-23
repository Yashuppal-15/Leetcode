class Solution {
public :

    bool solve ( TreeNode* root , long long int lowerBound , long long int upperBound ) {

        // Base case
        if ( root == NULL ) {
            return true ;
        }

        // 1 case hum solve kar lenge
        bool cond1 = ( root -> val > lowerBound ) ;
        bool cond2 = ( root -> val < upperBound ) ;

        // ab recursion solve kar lega
        bool LS = solve ( root -> left , lowerBound , root -> val ) ;
        bool RS = solve ( root -> right , root -> val , upperBound ) ;

        if ( cond1 && cond2 && LS && RS ) {        // ab har ek root par check karlo ke BST hai ya nhi
            return true ;
        }
        else {
            return false ;
        }
    }

    bool isValidBST ( TreeNode* root ) {

        long long int lowerBound = -2147483657 ;
        long long int upperBound = 2147483657 ;

        bool ans = solve ( root , lowerBound , upperBound ) ;
        return ans ;
    }
};
