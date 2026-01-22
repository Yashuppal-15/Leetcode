class Solution {
public:
    int firstUniqChar(string s) {
        deque<int> q;
        int freq[26] = {0};
        int ans = -1;

        for (int i = 0; i < s.length(); i++) {

            // I -> picking current character from string
            char ch = s[i];

            // II -> storing the freq at current character to array
            freq[ch - 'a']++;

            // III -> inserting the index of current character to queue
            q.push_back(i);

            // IV -> Ans find karna : unique character hai ya nahi
            while (!q.empty()) {

                // I -> picking the front value from queue
                char frontChar = s[q.front()];

                // II -> going to freq table to check the frontChar is unique or not
                if (freq[frontChar - 'a'] > 1) {

                    // character is repeating -> no ans
                    q.pop_front();
                }
                else {

                    // character is not repeating -> ans
                    ans = q.front();
                    break;
                }
            }
        }

        // Agar koi bhi ans nhi mila hai
        // iska matlab queue empty ho chuka hai
        if (q.empty()) {
            ans = -1;
        }

        return ans;
    }
};
