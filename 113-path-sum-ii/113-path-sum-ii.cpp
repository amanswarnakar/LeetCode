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
    void preorderTraversal(TreeNode *root, int t, vector<int> temp, vector<vector<int>> &ans){
      if(!root) return;
      if(!root->left and !root->right and root->val == t){
        temp.push_back(root->val);
        ans.push_back(temp);
        return;
      }
      temp.push_back(root->val);
      t -= root->val;
      preorderTraversal(root->left, t, temp, ans);
      preorderTraversal(root->right, t, temp, ans);
    }
  
    vector<vector<int>> pathSum(TreeNode* root, int t) {
      vector<vector<int>> ans;
      preorderTraversal(root, t, {}, ans);
      return ans;
    }
};