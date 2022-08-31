/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
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
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>{};

        stack<TreeNode*> cur;
        stack<TreeNode*> out;
        cur.push(root);
        while(!cur.empty()){
            TreeNode* temp = cur.top();cur.pop();
            out.push(temp);
            if(temp->left)
                cur.push(temp->left);
            if(temp->right)
                cur.push(temp->right);
        }
        while(!out.empty()){
            res.push_back(out.top()->val);out.pop();
        }
        return move(res);
    }
};

/*
68 / 68 test cases passed.
Status: Accepted
Runtime: 3 ms
Memory Usage: 8.5 MB
*/
