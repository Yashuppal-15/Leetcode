class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 0;
        int end = arr.size() - 1;

        // Termination condition
        while (start < end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Me A line par hu
                // And peak right main exist karta hai
                start = mid + 1;
            }
            else {
                // Me B line par hu
                // Ya to peak par hu ya peak left main hai
                end = mid;
            }
        }

        return start;
    }
};
