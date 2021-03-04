/*
This problem implements a stack to keep track of whether the pushed element could be popped from the stack
Step:
1. Push all the elements one by one to the stack
2. Pop element from the stack as long as the last element inside the stack is the same as the current popped element
3. If the stack is empty at the end, this is a valid stack sequence

Time: O(N)
Space: O(N) Worse Case : all the elements are pushed to the stack and no possible pop operation can be done
where N is the total element inside either the pushed or popped array
*/
class Solution {
private:
    stack<int> stack;
    int idx = 0;
    
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        for (int num : pushed) {
            
            stack.push(num);
            while (!stack.empty() && stack.top() == popped[idx]) {
                stack.pop();
                idx++;
            }
        }
        return stack.empty();
    }
};
