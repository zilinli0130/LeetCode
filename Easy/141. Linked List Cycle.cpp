/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*This problem implements two pointer method. If a cycle exists, then these two pointers will eventually meet.

Time: O(N)
Space: O(1)

*/
class Solution {
    
    public:

    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
      return false;  
    }
};

