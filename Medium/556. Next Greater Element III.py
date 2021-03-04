#Time : O(N)
#Space : O(1)

class Solution:
    def nextGreaterElement(self, n):
        s = list(str(n))
        
        #Find the first idx in which it is greater than its previous idx
        idx1 = len(s) - 1
        while idx1 > 0:
            if s[idx1] > s[idx1-1]:
                break
            idx1 -= 1
            
        if idx1 == 0: 
            return -1
        
        #Find the first idx in which it is greater than idx1 and then swap
        idx2 = len(s) - 1
        while idx2 >= idx1:
            if s[idx2] > s[idx1-1]:
                s[idx1-1], s[idx2] = s[idx2], s[idx1-1]
                break
            idx2 -= 1
        
        s[idx1:] = s[idx1:][::-1]
        result = int(''.join(s))
        
        return result if -2**31 - 1 <= result <= 2**31 - 1 else -1 #signed int32
