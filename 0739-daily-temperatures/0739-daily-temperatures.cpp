class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;

        for(int i = temperatures.size() - 1; i >= 0; i--) {
            int temp = temperatures[i];
            while(!s.empty() && s.top().first <= temp) {
                s.pop();
            }
            temperatures[i] = s.empty() ? 0 : s.top().second - i;
            s.push({temp, i});
        }
        return temperatures;
    }
};