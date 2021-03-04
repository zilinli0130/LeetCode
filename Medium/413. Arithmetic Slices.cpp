/*
This problem implements the Two Pointer method to traverse the whole array and find out all the Arithmetic subset.
Then we could calculate the result for each subset to add up to the final result

Time : O(N)
Space : O(1)
*/
class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if (A.empty()) {return 0;}
     
        int left = 0, right = 1, result = 0;
        while (right < A.size() - 1) {
            
            if (A[right] - A[right - 1] == A[right + 1] - A[right]) {
                right++;
                continue;
            } else if (A[right] - A[right - 1] != A[right + 1] - A[right] && right - left > 1) {
                result += helper(left, right);
                
            }
            left = right;
            right = left + 1;
        }
        
        if (right - left > 1) {
            result += helper(left, right);
        }
       return result;
    }
    
    int helper(int left, int right) {
        
        int sum = 0, count = right - left - 1;
        
        while (!count == 0) {
            sum += count;
            count--;
        }
        return sum;
    }
};
