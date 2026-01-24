class Solution {
public:
    string removeOccurrences ( string s , string part )
    {
        // step 1 : find part from s
        // when part found then erase it from s
        while ( s.find ( part ) != string :: npos )
        {
            // if inside loop, it means that part exists in s string
            s.erase ( s.find ( part ) , part.length ( ) ) ;
        }

        // step 2 : return s
        return s ;
    }
};

/*
T.C = O(N)
S.C = O(1)
No extra space used
*/
