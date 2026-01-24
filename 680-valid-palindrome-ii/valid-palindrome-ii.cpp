class Solution {
public:

    // Palindrome function
    bool checkPalindrome ( string s , int start , int end )
    {
        while ( start <= end )
        {
            if ( s[start] == s[end] )
            {
                start ++ ;
                end -- ;
            }
            else
            {
                return false ;
            }
        }

        return true ;
    }

    // Valid Palindrome II
    bool validPalindrome ( string s )
    {
        int N = s.length ( ) ;
        int start = 0 ;
        int end = N - 1 ;

        while ( start < end )
        {
            // step 1
            if ( s[start] == s[end] )
            {
                start ++ ;
                end -- ;
            }
            // step 2
            else
            {
                // only one removal allowed
                // remove s[start]
                bool ans1 = checkPalindrome ( s , start + 1 , end ) ;

                // remove s[end]
                bool ans2 = checkPalindrome ( s , start , end - 1 ) ;

                // step 3
                return ans1 || ans2 ;
            }
        }

        // agar yaha tak pahunch gaye ho to iska matlab
        // zero removal required
        return true ;
    }
};

/*
T.C = O(N)
S.C = O(1)
*/
