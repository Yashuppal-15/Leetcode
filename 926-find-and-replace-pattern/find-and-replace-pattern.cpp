class Solution {
public:

    // Function to normalize string
    // Converts string into a pattern form like "abb", "abc", etc.
    void createUpdatedMapping(string &str) {

        char mapping[300] = {0};                       // Mapping array to store new character mapping
        char start = 'a';                              // Start mapping from 'a'

        // Step 1: Create mapping for each unique character
        for (char ch : str) {

            // If character is not mapped yet
            if (mapping[ch] == 0) {
                mapping[ch] = start;                     // Assign next available character
                start++;                                 // Move to next character
            } 
        }

        // Step 2: Update original string using mapping
        for (int i = 0; i < str.length(); i++) {
            str[i] = mapping[str[i]];                    // Replace character with mapped value
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ans;

        createUpdatedMapping(pattern);                     // Normalize the pattern string

        // Step 2: Check each word
        for (string word : words) {
            string temp = word;                              // Create temporary copy

            createUpdatedMapping(temp);                     // Normalize the word

            // If normalized word matches normalized pattern
            if (temp == pattern) {
                ans.push_back(word);                      // Original word matches pattern
            }
        }

        return ans;                                        // Return all matching words
    }
};
