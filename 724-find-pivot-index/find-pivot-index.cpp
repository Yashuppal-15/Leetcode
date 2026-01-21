class Solution {
public:
    int bruteforce(vector<int>& nums) {                 // Brute force approach to find pivot index

        for(int i = 0; i < nums.size(); i++){          // Iterate through each index and treat it as a potential pivot

            int lsum = 0;                              // stores sum of elements on the left side
            int rsum = 0;                              // stores sum of elements on the right side
        
            for(int j = 0; j < i; j++){
                lsum += nums[j];                       // Calculate left sum (elements before index i)
            }

            for(int j = i + 1; j < nums.size(); j++){
                rsum += nums[j];                        // Calculate right sum (elements after index i)
            }

            if(lsum == rsum){                           // If left sum equals right sum, pivot index found
                return i;
            }
        }

        return -1;                                      // If no pivot index satisfies the condition
    }

    int pivotIndex(vector<int>& nums) {                 // Function called by LeetCode to return pivot index
        return bruteforce(nums);
    }
};
