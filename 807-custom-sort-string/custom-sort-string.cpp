class Solution {
public:
    // This static string will store the custom order
    // Static is required because comparator function must be static
    static string orderStr;

    // Custom comparator function
    // It decides which character should come first
    static bool compare(char a, char b) {

        // orderStr.find(a) gives the index of character 'a' in order string
        // orderStr.find(b) gives the index of character 'b' in order string
        // The character which appears earlier in 'order' should come first
        return orderStr.find(a) < orderStr.find(b);
    }

    string customSortString(string order, string s) {

        // Store order string in static variable so comparator can access it
        orderStr = order;

        // sort() rearranges characters of string s
        // begin() → starting iterator
        // end() → ending iterator
        // compare → custom comparator function
        sort(s.begin(), s.end(), compare);

        // Return the sorted string
        return s;
    }
};

// Definition of static variable outside class
string Solution::orderStr;
