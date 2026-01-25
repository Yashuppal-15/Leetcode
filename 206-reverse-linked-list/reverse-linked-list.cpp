//🔁 APPROACH 2: RECURSIVE APPROACH
class Solution {
public:

    // helper recursive function
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {

        // base case: when curr becomes NULL
        if (curr == NULL) {
            return prev;
        }

        ListNode* nextNode = curr->next;                  // store next node
        curr->next = prev;                                 // reverse link
        prev = curr;                                     // move prev and curr forward
        curr = nextNode;

        // recursive call
        return reverseUsingRecursion(prev, curr);
    }

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseUsingRecursion(prev, curr);
    }
};
