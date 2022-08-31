/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        vector<int> ans;
        
        stk.push(cur);
        
        do{
            cur = stk.top();
            
            //go to its leftmost child
            TreeNode* tmp = cur ? cur->left : NULL;
            while(tmp){
                stk.push(tmp);
                tmp = tmp->left;
            }
            
            //if it has left child, process leftmost child first
            cur = stk.top(); stk.pop();
            if(cur) ans.push_back(cur->val);
            
            //cut current node and its parent, 
            //so current node won't be traversed again
            if(stk.size() > 0) stk.top()->left = NULL;
            
            //deal with right child
            if(cur && cur->right) stk.push(cur->right);
        }while(!stk.empty());
        
        return ans;
    }
};

/*
70 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 8.1 MB
*/
