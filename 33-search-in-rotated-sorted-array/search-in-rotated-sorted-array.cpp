class Solution {
public:
    
    int binary_search(vector<int>& nums, int s, int e, int target) {
        
        while (s <= e) {
            
            int mid = s + (e - s) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        
        return -1;
    }
    
    int findPivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        
        while (s < e) {
            
            int mid = s + (e - s) / 2;
            
            if (nums[mid] > nums[e]) {
                // Me A line par hu
                // Pivot right main exist karta hai
                s = mid + 1;
            }
            else {
                // Me B line par hu
                // Pivot left main ya mid par ho sakta hai
                e = mid;
            }
        }
        
        return s;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int pivotIndex = findPivotIndex(nums);
        int ans = -1;
        
        // step 2 : line A
        if (nums[pivotIndex] <= target && target <= nums[n - 1]) {
            ans = binary_search(nums, pivotIndex, n - 1, target);
        }
        // step 2 : line B
        else {
            ans = binary_search(nums, 0, pivotIndex - 1, target);
        }
        
        // return target index
        return ans;
    }
};
