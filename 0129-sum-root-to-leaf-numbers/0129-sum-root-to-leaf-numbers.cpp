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
    void dfs(TreeNode *node, vector<int> &v, int &num){
      num = num * 10 + node->val;
      if(!node->left and !node->right) {
        v.emplace_back(num);
        num /= 10;
        return;
      }
      if(node->left)
        dfs(node->left, v, num);
      if(node->right)
        dfs(node->right, v, num);
      num /= 10;  
    }
    int sumNumbers(TreeNode* root) {
      vector<int> v;
      int num = 0;
      dfs(root, v, num);
      return accumulate(v.begin(), v.end(), 0);
    }
};