/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1*/

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
    bool isValidBST(TreeNode* root, int& minv, int& maxv) {
        if(!root) return true;
        if(!root->left && !root->right){
            minv = maxv = root->val;
            return true;
        }else if(root->left && root->right){
            int minl = INT_MAX, maxl = INT_MIN;
            //if subtree is invalid, return immediately!!
            if(!isValidBST(root->left, minl, maxl)) return false;
            if(maxl >= root->val) return false;
            
            int minr = INT_MAX, maxr = INT_MIN;
            if(!isValidBST(root->right, minr, maxr)) return false;
            if(minr <= root->val) return false;
            
            minv = minl;
            maxv = maxr;
            
            return true;
        }else if(!root->right){
            //left subtree is not empty
            int minl = INT_MAX, maxl = INT_MIN;
            if(!isValidBST(root->left, minl, maxl)) return false;
            if(maxl >= root->val) return false;
            maxv = root->val;
            minv = minl;
            return true;
        }else/* if(!root->left)*/{
            //right subtree is not empty
            int minr = INT_MAX, maxr = INT_MIN;
            if(!isValidBST(root->right, minr, maxr)) return false;
            if(minr <= root->val) return false;
            minv = root->val;
            maxv = maxr;
            return true;
        }
    }
    bool isValidBST(TreeNode* root) {
         int rootmin = INT_MAX, rootmax = INT_MIN;
        return isValidBST(root, rootmin, rootmax);
    }
};

/*
80 / 80 test cases passed.
Status: Accepted
Runtime: 21 ms
Memory Usage: 22 MB
*/
