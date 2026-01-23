class TrieNode {
public:
    char value;
    bool isTerminal;
    TrieNode* children[26];
    int childCount;

    // Constructor
    TrieNode(char ch) {
        value = ch;
        isTerminal = false;
        childCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:

    // ---------------- STEP 1 ----------------
    // Insert word into Trie
    void insertWord(TrieNode* root, string word) {

        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            child = new TrieNode(ch);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursion
        insertWord(child, word.substr(1));
    }

    // ---------------- STEP 2 ----------------
    // Find Longest Common Prefix
    void findLCP(string &ans, TrieNode* root) {

        // Stop if node is terminal OR more than one child
        if (root->isTerminal == true || root->childCount != 1) {
            return;
        }

        // Find the only child
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                ans.push_back(root->children[i]->value);
                findLCP(ans, root->children[i]);
                break;
            }
        }
    }

    // ---------------- MAIN FUNCTION ----------------
    string longestCommonPrefix(vector<string>& strs) {

        // Edge case
        if (strs.size() == 0) return "";

        // Create root
        TrieNode* root = new TrieNode('-');

        // Insert all strings into Trie
        for (string str : strs) {
            insertWord(root, str);
        }

        // Find LCP
        string ans = "";
        findLCP(ans, root);

        return ans;
    }
};
