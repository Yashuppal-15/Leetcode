class Solution {
public:
    int secondHighest(string s) {
        bool seen[10] = {};
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) seen[s[i] - '0'] = true;
        }

        int count = 0;
        for (int i = 9; i >= 0; --i) {
            if (seen[i] && ++count == 2) return i;
        }

        return -1;
    }
};