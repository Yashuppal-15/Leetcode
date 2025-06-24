class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {
            // Reverse the first k characters in the current 2k block
            // If less than k characters left, reverse all of them
            int j = min(i + k, n);
            reverse(s.begin() + i, s.begin() + j);
        }

        return s;
    }
};