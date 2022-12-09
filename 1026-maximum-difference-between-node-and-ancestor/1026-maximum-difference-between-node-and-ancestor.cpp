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
    int traverse(TreeNode *node, int l, int r){
      if(!node) return r - l;
      r = max(node->val, r);
      l = min(node->val, l);
      int left = traverse(node->left, l, r);
      int right = traverse(node->right, l, r);
      return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
      return traverse(root, root->val, root->val);
    }
};