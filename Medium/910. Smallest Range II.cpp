/*The idea of this problem is to find an arbitary position inside the array,
We add K to all the values before this position and subtract K to all the values
after this position. We find the max and min values of this revised array and calculate 
the result. We save the result and keep moving to the next arbitary position and update
the result every time.

Time : O(N)
Space : O(1)

*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        
        sort(A.begin(), A.end());
        int size = A.size(), result = A[size - 1] - A[0];
        
        for (int i = 0; i < size - 1; i++) {
            
            int potentialMax = max(A[i] + K, A[size - 1] - K);
            int potentialMin = min(A[0] + K, A[i + 1] - K);
            result = min(result, potentialMax - potentialMin);
        }
      return result;
    }
};