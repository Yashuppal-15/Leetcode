class Solution {
public:
    
    // Our own data type to store:
    // value, row index (which list), column index (position in that list)
    class Info {
    public:
        int data;
        int rowIndex;
        int colIndex;
        
        Info(int data, int rowIndex, int colIndex) {
            this->data = data;
            this->rowIndex = rowIndex;
            this->colIndex = colIndex;
        }
    };
    
    // Comparator for Min Heap
    // Node with smaller data value comes first
    class Compare {
    public:
        bool operator()(Info* first, Info* second) {
            return first->data > second->data;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        // Create Min Heap
        priority_queue<Info*, vector<Info*>, Compare> pq;   
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        // --------------------------------------------------
        // STEP 1: Insert first element of each list
        // --------------------------------------------------
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i][0];
            Info* tempNode = new Info(element, i, 0);
            pq.push(tempNode);
            
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        
        // Initial range
        int ansStart = mini;
        int ansEnd = maxi;
        
        // --------------------------------------------------
        // STEP 2: Process heap
        // --------------------------------------------------
        while (!pq.empty()) {
            Info* topNode = pq.top();
            pq.pop();
            mini = topNode->data;
            
            // Update range if smaller range found
            if (maxi - mini < ansEnd - ansStart) {
                ansStart = mini;
                ansEnd = maxi;
            }
            
            // --------------------------------------------------
            // STEP 3: Push next element from same list
            // --------------------------------------------------
            if (topNode->colIndex + 1 < nums[topNode->rowIndex].size()) {
                
                int nextElement = nums[topNode->rowIndex][topNode->colIndex + 1];
                Info* newNode = new Info(
                    nextElement,
                    topNode->rowIndex,
                    topNode->colIndex + 1
                );
                
                pq.push(newNode);
                
                // Update maximum
                maxi = max(maxi, nextElement);
            }
            else {
                // If any list is exhausted, we cannot cover all lists
                break;
            }
        }
        
        return {ansStart, ansEnd};
    }
};

// Time Complexity:
// Heap creation: O(K log K)
// While loop: O(N log K)
// Overall: O(N log K)
//
// Space Complexity:
// Min Heap stores at most K elements
// O(K)
//
// Where:
// K = number of lists
// N = total number of elements in all lists
