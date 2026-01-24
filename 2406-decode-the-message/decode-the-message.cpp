class Solution {
public:
    string decodeMessage(string key, string message) {

        // Step 1: Create mapping for characters
        char start = 'a';
        char mapping[300] = {0};

        // Build mapping using key
        for (auto ch : key) {
            if (ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        // Step 2: Decode the message
        string ans = "";
        for (auto ch : message) {
            if (ch == ' ') {
                ans.push_back(' ');
            } else {
                ans.push_back(mapping[ch]);
            }
        }

        // Step 3: Return decoded message
        return ans;
    }
};
