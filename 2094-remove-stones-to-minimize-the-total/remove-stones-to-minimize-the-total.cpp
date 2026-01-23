class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> maxheap;                       // Max heap to always get the pile with maximum stones
        
        // Step 1: Push all piles into max heap
        for(int pile = 0; pile < piles.size(); pile++){                    // Time Complexity: O(N log N)
            maxheap.push(piles[pile]);
        }
        
        // Step 2: Perform k operations
        // In each operation, remove floor(pile / 2) stones from the largest pile
        while(k--){                                                          // Time Complexity: O(K log N)
            int maxStonesPile = maxheap.top();
            maxheap.pop();
            
            maxStonesPile = maxStonesPile - floor(maxStonesPile / 2);    // Remaining stones after removing floor
            maxheap.push(maxStonesPile);                                 // Push updated pile back into heap
        } 
        
        // Step 3: Calculate the sum of remaining stones
        int sum = 0;
        while(!maxheap.empty()){                                         // Time Complexity: O(N log N)
            sum += maxheap.top();
            maxheap.pop();
        }
        
        return sum;
    }
};

// Creating max heap      → O(N log N)
// K operations on heap   → O(K log N)
// Summing heap elements  → O(N log N)
//
// Overall Time Complexity: O(N log N)

// Max heap stores N elements
// Space Complexity: O(N)
//
// Where:
// N = number of piles
// K = number of operations
