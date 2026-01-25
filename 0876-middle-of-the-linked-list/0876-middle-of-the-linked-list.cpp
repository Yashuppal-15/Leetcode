class Solution {
public:
    // Function to get the middle node of the linked list
    ListNode* middleNode(ListNode* head) {

        // Step 1: Count length of linked list
        ListNode* temp = head;   // temp pointer to traverse list
        int count = 0;

        while (temp != NULL) {
            count++;             // increase count for each node
            temp = temp->next;   // move to next node
        }

        // Step 2: Move to middle position
        int mid = count / 2;     // middle index (0-based)

        temp = head;             // reset temp to head

        while (mid--) {
            temp = temp->next;   // move temp to middle node
        }

        return temp;             // return middle node
    }
};
