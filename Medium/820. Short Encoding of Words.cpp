/*
This problem implements a build-in method to sort all the strings in descending order.
In such way, it is able to compare if the next string is the suffix of current result

Time : O(N*log(N) + N*M)
Space : O(N*M)
where N is the total number of strings inside the array and M is the average length of a string

*/
bool compare(string &str1,string &str2) {return str1.length() > str2.length();}

class Solution {
public:
    
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare);
        string result = words[0] + "#";
        
        for(int i = 1;i < words.size(); i++){
            if(result.find(words[i] + "#") == string::npos) {result += words[i] + "#";}
        }
        return result.length();
    }
};