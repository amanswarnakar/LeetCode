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
    void dfs(TreeNode * &node, set<int> &st, vector<TreeNode *> &ans){
      if(!node) return;
      dfs(node->left, st, ans);
      dfs(node->right, st, ans);
      if(st.find(node->val) != st.end()){
        if(node->left) ans.emplace_back(node->left);
        if(node->right) ans.emplace_back(node->right);
        node = NULL;
        delete node;
      }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      vector<TreeNode *> ans;
      set<int> st(to_delete.begin(), to_delete.end());
      dfs(root, st, ans);
      if(root) ans.emplace_back(root);
      return ans;
    }
};