//Fast and slow Algoritm (Floyd’s Cycle Detection + Math logic)
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        // Step 1: Find loop using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL) {
            fast = fast->next;

            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }

            // If slow and fast meet, loop exists
            if (slow == fast) {
                break;
            }
        }

        // If fast reached NULL, no loop present
        if (fast == NULL) {
            return NULL;
        }

        // Step 2: Find starting point of loop
        slow = head;

        // Move both pointers one step at a time
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow (or fast) is the starting point of loop
        return slow;
    }
};
