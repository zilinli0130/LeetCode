# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

#This problem implements three pointer method
#We need to keep track of each pointer and make
#sure the update order of pointers are correct
#
#Time : O(N) where N is the number of nodes in a linked list
#Space : O(1)

class Solution(object):
    def swapPairs(self, head):
        if not head or not head.next:
            return head
        
        fakeNode = ListNode(0)
        p1 = fakeNode
        p2 = head
        
        while p2 is not None and p2.next is not None:
            
            #Swap
            p3 = p2.next
            p1.next = p3
            p2.next = p3.next
            p3.next = p2
            
            #Update
            p1 = p2
            p2 = p2.next
        return fakeNode.next
        