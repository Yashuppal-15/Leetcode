class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        auto calcArea = [&](int rightIdx) {
            int hIdx = st.top(); st.pop();
            int leftIdx = st.empty() ? -1 : st.top();
            return heights[hIdx] * (rightIdx - leftIdx - 1);
        };

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                maxArea = max(maxArea, calcArea(i));
            st.push(i);
        }

        while (!st.empty())
            maxArea = max(maxArea, calcArea(n));

        return maxArea;
    }
};