/*The problem impelments two pointer method:
First we need to sort this array, then define a left and right pointer. Left pointer represents the light person whereas the right pointer represents heavy person. If the 
sum of the weight mapped with these two pointers is less or equal limit, we should increase
the result by 1 and increase left pointer by 1, decrease right pointer by 1, else we decrease the right pointer to seek for a less weight person which can pair the current light person.

Time : O(N) where N is number of person inside the people array
Space : O(1)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, res = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                res++;
                left++;
                right--;
            } else {
                right--;
                res++;
            }
        }
    return res;
    }
};