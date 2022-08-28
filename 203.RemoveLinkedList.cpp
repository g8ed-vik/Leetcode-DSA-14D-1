/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *cur;
        
        //deal with leading 'val's
        while(head != NULL && head->val == val) head = head->next;
        
        //deal with 'val's not in head of list
        cur = head;
        while(cur != NULL){
            if(cur->val == val){
                prev->next = cur->next;
                /**
                [1,2,2,1]: prev:1,cur:2
                [1,2,1]: prev:1,cur:2
                [1,1]: prev:1,cur:1
                **/
            }else{
                //move prev when the next node of prev is not 'val'
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

/*
66 / 66 test cases passed.
Status: Accepted
Runtime: 59 ms
Memory Usage: 14.9 MB
*/
