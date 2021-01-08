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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL and l2 == NULL) {
            return l1;
        } 
        if (l1 == NULL || l2 == NULL) {
            return l1 == NULL ? l2 : l1;
        }
        
        ListNode *p1 = l1;
        ListNode *p1Prev = NULL;
        ListNode *p2 = l2;
	
        while (p1 != NULL && p2 != NULL) {
            //Correct Order
            if (p1->val < p2->val) {
                p1Prev = p1;
                p1 = p1->next;
            } else {
                //Incorrect Order
                if (p1Prev != NULL) {
                    p1Prev->next = p2;
                }
                p1Prev = p2; //If p1Prev is NULL
                p2 = p2->next;
                p1Prev->next = p1;
            }
        }

        if (p1 == NULL) {
            p1Prev->next = p2;
        }
	    //return l1->val < l2->val ? l1 : l2;
        return l1;
    }
};