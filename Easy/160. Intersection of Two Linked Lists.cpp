/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Brute Force Solution
Time : O(N)
Space : O(1)

optimal solution : switch pointers to the other head if it is NULL
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int idxA = 0, idxB = 0;
        ListNode *ptr1 = headA, *ptr2 = headB;
        while (ptr1 != NULL || ptr2 != NULL) {
            if (ptr1 != NULL) {ptr1 = ptr1->next; idxA++;}
            if (ptr2 != NULL) {ptr2 = ptr2->next; idxB++;}
        }
        
        if (idxA > idxB) {
            while (idxA != idxB) {headA = headA->next; idxA--;}
        } else if (idxA < idxB) {
            while (idxA != idxB) {headB = headB->next; idxB--;}
        }
        
        if (headA == headB && headA != NULL) {return headA;}
        
        while (headA != NULL || headB != NULL) {
            if (headA != NULL) {headA = headA->next;}
            if (headB != NULL) {headB = headB->next;}
            if (headA == headB) {return headA;}
        }
        
        //Delete pointers to avoid memory leak
        delete ptr1;
        delete ptr2;
        return NULL;
    }
};
