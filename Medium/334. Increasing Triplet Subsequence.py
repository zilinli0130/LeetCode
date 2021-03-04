#We keep updating the value of idx1 and idx2. If we
#find a value which is greater than idx2, we could
#simply return True.
#Time : O(N)
#Space : O(1)

class Solution:
    def increasingTriplet(self, nums):
        
        idx1 = float("inf")
        idx2 = float("inf")
        
        for num in nums:
            if num < idx1: 
                idx1 = num
            if num < idx2 and num > idx1: 
                idx2 = num
            if num > idx2: 
                return True
        return False
