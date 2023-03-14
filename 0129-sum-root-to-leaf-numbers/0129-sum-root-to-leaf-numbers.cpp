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
    void dfs(TreeNode *node, int &num, int &ans){
      num = num * 10 + node->val;
      if(!node->left and !node->right) {
        ans += num;
        num /= 10;
        return;
      }
      if(node->left)
        dfs(node->left, num, ans);
      if(node->right)
        dfs(node->right, num, ans);
      num /= 10;  
    }
    int sumNumbers(TreeNode* root) {
      int num = 0, ans = 0;
      dfs(root, num, ans);
      return ans;
    }
};