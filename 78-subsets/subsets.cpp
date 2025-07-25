class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        /*BIT MASKING
        /*any set will have 2^n subsets, u can either take(1) an element or dont take(0) an element.
        0 to 2^n - 1, would be pick bit strings if we mask each element of arr like above, 0 => none picked, 2^n-1 => all picked, 1 => one element, we can say index 0 wala is picked
        */
        int n = arr.size();
        vector<vector<int>> subsets;
        
        for(int i=0; i<pow(2, n); i++) {
            int j=0;
            vector<int> subset;
            while(j<n) {
                if(i & (1<<j)) {
                    subset.push_back(arr[j]);
                }
                j++;
            }
            subsets.push_back(subset);
        }
        
        return subsets;
    }
};