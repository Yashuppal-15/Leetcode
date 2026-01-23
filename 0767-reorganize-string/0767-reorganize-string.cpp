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

    // Comparator for Max Heap (based on frequency)
    class Compare {
    public:
        bool operator()(Info first, Info second) {
            return first.count < second.count;        // character with higher frequency should come first
        }
    };

    string reorganizeString(string s) {

        // STEP 1: Count frequency of each character
        int frequency[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            frequency[s[i] - 'a']++;
        }

        // STEP 2: Push all characters with frequency > 0 into max heap
        priority_queue<Info, vector<Info>, Compare> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(frequency[i] > 0) {
                Info temp(i + 'a', frequency[i]);
                maxHeap.push(temp);
            }
        }

        // STEP 3: Reorganize the string
        string ans = "";

        while(maxHeap.size() > 1) {

            Info first = maxHeap.top();                   // take two most frequent characters
            maxHeap.pop();

            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.ch);                      // add both characters to answer string
            ans.push_back(second.ch);

            first.count--;                               // decrease their frequency
            second.count--;

            // push back if still remaining
            if(first.count > 0) {
                maxHeap.push(first);
            }

            if(second.count > 0) {
                maxHeap.push(second);
            }
        }

        // STEP 4: Handle last remaining character (if any)
        if(maxHeap.size() == 1) {
            Info last = maxHeap.top();
            maxHeap.pop();

            // if frequency > 1, cannot reorganize
            if(last.count > 1) {
                return "";
            }
            ans.push_back(last.ch);
        }

        return ans;
    }
};
