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
    int helper(TreeNode *node, int &ans){
      if(!node) return 0;
      int left = max(0, helper(node->left, ans));
      int right = max(0, helper(node->right, ans));
      ans = max(ans, left + right + node->val);
      return max(left, right) + node->val;
    }
    int maxPathSum(TreeNode* root) {
      int ans = INT_MIN;
      helper(root, ans);
      return ans;
    }
};