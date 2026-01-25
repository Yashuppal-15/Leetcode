class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Case 1: Empty linked list
        if (head == NULL) {
            return head;
        }
        // Case 2: Single element list
        if (head->next == NULL) {
            return head;
        }
        // Case 3: More than one element
        ListNode* temp = head;

        // Traverse till last node
        while (temp != NULL && temp->next != NULL) {

            // If current node value == next node value
            if (temp->val == temp->next->val) {

                ListNode* nextNode = temp->next;           // Duplicate found
                temp->next = nextNode->next;               // Skip duplicate node
                nextNode->next = NULL;                    // Isolate duplicate node

                delete nextNode;                           // Delete duplicate node
            }
            else {
                temp = temp->next;                      // If values are different, move forward
            }
        }

        return head;                                      // Return updated head
    }
};
