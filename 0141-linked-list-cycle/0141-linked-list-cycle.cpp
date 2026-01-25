class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Step 1: Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2: Traverse the list
        while (fast != NULL) {

            fast = fast->next;          // fast moves one step

            if (fast != NULL) {
                fast = fast->next;      // fast moves second step
                slow = slow->next;      // slow moves one step
            }

            // Step 3: Check if slow and fast meet
            if (slow == fast) {
                return true;            // cycle detected
            }
        }

        // Step 4: If fast reaches NULL, no cycle
        return false;
    }
};
