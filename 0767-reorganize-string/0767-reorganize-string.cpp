class Solution {
public:
    // Custom data type to store character and its frequency
    class Info {
    public:
        char ch;
        int count;

        Info(char ch, int count) {
            this->ch = ch;
            this->count = count;
        }
    };

    // Comparator for max heap (higher frequency first)
    class Compare {
    public:
        bool operator()(Info* a, Info* b) {
            return a->count < b->count;
        }
    };

    string reorganizeString(string s) {

        // ---------------- STEP 1 ----------------
        // Count frequency of each character
        unordered_map<char, int> frequency;
        for (char ch : s) {
            frequency[ch]++;
        }

        // ---------------- STEP 2 ----------------
        // Create max heap based on frequency
        priority_queue<Info*, vector<Info*>, Compare> maxHeap;

        for (auto it : frequency) {
            maxHeap.push(new Info(it.first, it.second));
        }

        // ---------------- STEP 3 ----------------
        // Build the reorganized string
        string ans = "";

        while (maxHeap.size() > 1) {
            // Take two most frequent characters
            Info* first = maxHeap.top();
            maxHeap.pop();

            Info* second = maxHeap.top();
            maxHeap.pop();

            // Append characters
            ans.push_back(first->ch);
            ans.push_back(second->ch);

            // Decrease frequency
            first->count--;
            second->count--;

            // Push back if still available
            if (first->count > 0) maxHeap.push(first);
            if (second->count > 0) maxHeap.push(second);
        }

        // ---------------- STEP 4 ----------------
        // If one character remains
        if (maxHeap.size() == 1) {
            Info* last = maxHeap.top();
            maxHeap.pop();

            // If remaining count > 1, not possible
            if (last->count > 1) return "";

            ans.push_back(last->ch);
        }

        return ans;
    }
};
