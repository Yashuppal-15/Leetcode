
//Definition for singly-linked list.

// struct ListNode {
//     int val;
//     ListNode *next;

//     ListNode(int x) {
//         val = x;
//         next = NULL;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;                    // prev pointer will point to previous node
        ListNode* curr = head;                    // curr pointer starts from head

        // loop until curr becomes NULL
        while (curr != NULL) {

            ListNode* nextNode = curr->next;       // store next node before breaking the link
            curr->next = prev;                     // reverse the current node pointer
            prev = curr;                           // move prev one step ahead
            curr = nextNode;                      // move curr one step ahead
        }

        return prev;                               // prev will become new head
    }
};
