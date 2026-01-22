class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;          // store the max element's index
        vector<int> ans;       // store the max element

        // Step 1: process the first window for "k time"
        for (int index = 0; index < k; index++) {

            int element = nums[index];

            // Agar queue me element chota hai
            // remove all smaller elements from back
            while (!q.empty() && element > nums[q.back()]) {
                q.pop_back();
            }

            // Yaha tak pahuch sakta hu
            // Ya to queue me element chota nhi hai
            // Ya queue empty ho chuka hai
            q.push_back(index);
        }

        // Step 2: process remaining windows
        for (int index = k; index < nums.size(); index++) {

            // purani window ka ans store kar do
            ans.push_back(nums[q.front()]);

            // Remove
            // I -> remove the out of range index from queue
            if (!q.empty() && index - q.front() >= k) {
                q.pop_front();
            }

            // II -> remove chota index from queue
            // Agar queue me element chota hai
            while (!q.empty() && nums[index] > nums[q.back()]) {
                q.pop_back();
            }

            // Addition
            // Yaha tak pahuch sakta hu
            // Ya to queue me element chota nhi hai
            // Ya queue empty ho chuka hai
            q.push_back(index);
        }

        // last window ka ans store kar lo
        ans.push_back(nums[q.front()]);

        return ans;
    }
};
