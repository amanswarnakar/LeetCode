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
    bool helper(TreeNode *root, long low, long high){
      if(!root) return true;
      if(root->val > low and root->val < high){
        bool l = helper(root->left, low, root->val);
        bool r = helper(root->right, root->val, high);
        return l and r;
      } else return false;
    }
    bool isValidBST(TreeNode* root) {
      bool ans = helper(root, LONG_MIN, LONG_MAX);
      return ans;
    }
};