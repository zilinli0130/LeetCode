/* This problem implements stack

Time : O(N)
Space : O(N)
*/

class Solution {
public:
    bool isValid(string s) {
        
         string openingBrackets = "([{";
         string closingBrackets = ")]}";
         unordered_map<char,char> matchingBrackets{{')', '('}, {']', '['}, {'}', '{'}};
         stack<char> stack;
         
         for (char element : s) {
             if (openingBrackets.find(element) != string::npos) {
                 stack.push(element);
             } else if (closingBrackets.find(element) != string::npos) {
                 if (stack.size() == 0) {
                     return false;
                 } else if (stack.top() == matchingBrackets[element]) {
                     stack.pop();
                 } else {
                     return false;
                 }
             }
         }
        return stack.size() == 0;
    }
};