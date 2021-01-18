/*This method implements backtracking method to find the output
Time : O(5N) 
Space : O(N)

*/
class Solution {
public:
    int countVowelStrings(int n) {
        int result = 0;
        unordered_map<int, int> resultMap = count(n);
        for(int i = 1; i <= 5; i++) {
            result += resultMap[i];
        }
        return result;
    }
    
    unordered_map<int, int> count(int n) {
        
        if (n == 1) {
            unordered_map<int, int> hashmap;
            for(int i = 1; i <= 5; i++) {
                hashmap[i] = 1;
            }
            return hashmap;
        }
        
        unordered_map<int, int> lastResultMap = count(n - 1);
        unordered_map<int, int> nextResultMap;
        int i = 1, sum = 0;
        while (i <= 5) {
            for (int j = i; j <=5; j++) {
                sum += lastResultMap[j];
            }
            nextResultMap[i] = sum;
            sum = 0;
            i++;
        }
        return nextResult;
    }
};