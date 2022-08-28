/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            } else if(s[i] == ')') {
                if(i == 0 ||  t.empty() || t.top() != '(') {
                    return false;
                }
                t.pop();
            } else if(s[i] == ']') {
                if(i == 0 || t.empty() || t.top() != '[') {
                    return false;
                }
                t.pop();
            } else if(s[i] == '}') {
                if(i == 0 || t.empty() || t.top() != '{') {
                    return false;
                }
                t.pop();
            }
        }
        return t.empty();
    }
};

/*
92 / 92 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 6.4 MB
*/
