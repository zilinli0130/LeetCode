/*
This problem implements a map strategy to find out the roman number.
Time : O(1)
Space : O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        
        string result = "";
        unordered_map<int, string> hashmap;
        vector<int> integer = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman = {"I","IV", "V","IX", "X", "XL","L", "XC", "C", "CD", "D", "CM", "M"};
       
        while (num > 0) {
            
            for (int idx = 0; idx < integer.size(); idx++) {
                
                if (num >= 1000) {
                    num -= integer[integer.size() - 1];
                    result += roman[integer.size() - 1];
                    break;
                }
                if (num < integer[idx]) {
                    num -= integer[idx - 1];
                    result += roman[idx - 1];
                    break;
                } else if (num == integer[idx]) {
                    num -= integer[idx];
                    result += roman[idx];
                    break;
                }
            }
        }
        return result;
    }
};