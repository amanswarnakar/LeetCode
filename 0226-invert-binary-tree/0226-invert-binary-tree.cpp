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
    TreeNode* invertTree(TreeNode* root) {
      if(!root or (!root->left and !root->right)) return root;
      else {
        // TreeNode *r = root->right;
        // root->right = root->left;
        // root->left = r;
        swap(root->right, root->left);
      }
      invertTree(root->right);
      invertTree(root->left);
      return root;
    }
};