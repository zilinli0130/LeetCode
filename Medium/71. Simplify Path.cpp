/* This problem implements the stack method. First we need to split the string with tokens separated by forward slash "/". 
After that, we need to iterate through all the tokens and build up a stack containing final results

Time: O(N)
Space: O(N)

*/
#include <sstream>

class Solution {
public:
    
    string simplifyPath(string path) {
        
        //Split the string separated by forward slash "/"
        bool startWithSlash = path[0] == '/';
        istringstream iss(path);
        string token;
        vector<string> tokens;
        while (getline(iss, token, '/')) { tokens.push_back(token);}
        
        //Build up the stack to store important tokens
        vector<string> stack;
        if (startWithSlash) {
            stack.push_back("");
        }
        for (string token : tokens) {
            
            if (!token.length() || token == ".") {continue;}
            
            if (token == "..") {
                if (stack.size() == 0 || stack[stack.size() - 1] == "..") {
                    stack.push_back(token);
                } else if (stack[stack.size() - 1] != "") {
                    stack.pop_back();
                }
            } else {stack.push_back(token);}
        }
        if (stack.size() == 1 && stack[0] == "") {return "/";}
        
        //Output the string
        ostringstream oss;
        for (auto i = 0; i < stack.size(); i++) {
            if (i != 0) { oss<<"/"; }
            oss<<stack[i];
        }
	 return oss.str(); 
    }
};
