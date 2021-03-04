/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head != NULL) {
            
            //Skipped all the duplicate nodes
            if (head->next != NULL && head->val == head->next->val) {
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                //Connect the node before the first duplicate node to the node after the last duplicate node
                prev->next = head->next;
            } else {
                //Move forward
                prev = prev->next;
            }
            //Move forward
            head = head->next;
        }
        return dummy->next;
    }
};
