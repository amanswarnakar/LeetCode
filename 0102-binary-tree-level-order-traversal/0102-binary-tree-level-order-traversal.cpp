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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if(!root) return {};
      vector<vector<int>> ans;
      queue<TreeNode *> q;
      q.emplace(root);
      int level = 0;
      while(!q.empty()){
        int sz = q.size();
        vector<int> temp;
        for(auto i = 0; i < sz; i++){
          auto node = q.front(); q.pop();
          temp.emplace_back(node->val);
          if(node->left) q.emplace(node->left);
          if(node->right) q.emplace(node->right);
        }
        ans.emplace_back(temp);
        level++;
      }
      return ans;
    }
};