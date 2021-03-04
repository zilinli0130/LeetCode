/*This problem impements greedy algorithm with four times of sort()
We need to ensure that both words has the same letters with the same counts
Time : O(Nlog(N) + Mlog(M))
Space : O(X + Y)
N is the total number of letters in word1
M is the total number of letters in word2
X is the number of same letters in word1
Y is the number of same letters in word2
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()) {
            return false;
        }
        
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        
        unordered_map<char, int> hashmap1, hashmap2;
        vector<int> word1Count, word2Count;
        vector<char> word1Char, word2Char;
        for(char letter: word1) {
            hashmap1[letter]++;
        }
        for(char letter : word2) {
            hashmap2[letter]++;
        }
        for(auto i : hashmap1) {
            word1Char.push_back(i.first);
            word1Count.push_back(i.second);
        }
        for(auto i : hashmap2) {
            word2Char.push_back(i.first);
            word2Count.push_back(i.second);
        }
        
        if (word1Count.size() != word2Count.size() || word1Char.size() != word2Char.size()) {
            return false;
        }
        
        vector<int> sortedWord1Count(word1Count), sortedWord2Count(word2Count);
	    sort(sortedWord1Count.begin(), sortedWord1Count.end());
        sort(sortedWord2Count.begin(), sortedWord2Count.end());
        for (int i = 0; i < sortedWord1Count.size(); i++) {
            if(sortedWord1Count[i] != sortedWord2Count[i] || word1Char[i] != word2Char[i]) {
                return false;
            }
        }
      return true;  
    }
};
