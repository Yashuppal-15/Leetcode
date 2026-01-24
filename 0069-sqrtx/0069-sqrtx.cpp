class Solution {
public:
    int mySqrt(int x) {

        int s = 0;                                      // start of search space
        int e = x;                                     // end of search space (sqrt(x) <= x)
        long long int mid = s + (e - s) / 2;   // mid calculated using long long to avoid overflow
        int ans = -1;                                 // stores best possible answer
  
        while (s <= e) {                        // binary search loop

            // kya mid hi to ans nahi hai to return mid
            if (mid * mid == x) {                      // if perfect square
                return mid;                          // exact square root found
            }

            // agar mid * mid > x hai to left me chale jao
            else if (mid * mid > x) { 
                e = mid - 1;                               // move left
            }

            // agar mid * mid < x hai to ans me mid store karo + right me chale jao
            else {
                ans = mid;                           // store possible answer
                s = mid + 1;                        // move right
            }

            mid = s + (e - s) / 2;                          // update mid
        }

        return ans;                                        // return floor(sqrt(x))
    }
};
