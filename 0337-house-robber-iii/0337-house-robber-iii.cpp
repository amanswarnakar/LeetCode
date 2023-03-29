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
  int helper(TreeNode *node, int &l, int &r){
    if(!node) return 0;
    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = helper(node->left, ll, lr);
    r = helper(node->right, rl, rr);
    return max(l + r, node->val + ll + lr + rl + rr);
  }
  int rob(TreeNode* root) {
    int l = 0, r = 0;
    return helper(root, l, r);
  }
};