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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newList = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p3 = newList;
        int extraDigit = 0;
        
        while (p1 != NULL || p2 != NULL) {
            
            int p1Val = p1 != NULL ? p1->val : 0;
            int p2Val = p2 != NULL ? p2->val : 0;
            int totalDigitSum = p1Val + p2Val + extraDigit;
            int newListVal = totalDigitSum >= 10 ? totalDigitSum - 10 : totalDigitSum;
            extraDigit = totalDigitSum >= 10 ? 1 : 0;
            
            p3->next = new ListNode(newListVal);
            p3 = p3->next;
            if (p1 != NULL) {p1 = p1->next;}
            if (p2 != NULL) {p2 = p2->next;}
        }
        if (extraDigit == 1) {p3->next = new ListNode(1);}
       return newList->next; 
    }
};