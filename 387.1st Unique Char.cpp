/*Given a string s, find the first non-repeating character in it and return its index. 
  If it does not exist, return -1.
Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        
        vector<int> start(26), count(26);
        int ans = INT_MAX;
        
        for(int i = 0; i < s.size(); i++){
            int cix = s[i] - 'a';
            if(count[cix]==0){
                start[cix] = i;
                count[cix] = 1;
            }else{
                count[cix] += 1;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(count[i] == 1){
                ans = min(ans, start[i]);
            }
        }
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};
105 / 105 test cases passed.
Status: Accepted
Runtime: 50 ms
Memory Usage: 10.7 MB
/*

*/
