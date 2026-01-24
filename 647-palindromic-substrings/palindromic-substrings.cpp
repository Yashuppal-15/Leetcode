class Solution {
public:
    // expand function
    // i = left pointer
    // j = right pointer
    // this function counts palindromes by expanding from center
    int expand ( string s , int i , int j )
    {
        int count = 0 ;

        // jab tak substring palindrome ho tab tak me count inc karunga, otherwise loop rok dunga
        while ( i >= 0 && j < s.length ( ) && s[i] == s[j] )
        {
            count ++ ;   // ek palindrome mila
            i -- ;       // left expand
            j ++ ;       // right expand
        }

        return count ;
    }

    // main function to count palindromic substrings
    int countSubstrings ( string s )
    {
        int totalCount = 0 ;
        int center = 0 ;

        while ( center < s.length ( ) )
        {
            int oddCount = expand ( s , center , center ) ;        // step 1 : odd length palindrome
            int evenCount = expand ( s , center , center + 1 ) ;    // step 2 : even length palindrome
            totalCount = totalCount + oddCount + evenCount ;        // step 3 : total count

            center ++ ;                                            // increase center
        }

        return totalCount ;
    }
};

/*
T.C = O(N)
S.C = O(1)
N = length of string s
*/
