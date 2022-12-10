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
    int mod = 1e9+7;
    int dfs(TreeNode *node, vector<int> &v){
      if(!node) return 0;
      int sz = v.size();
      v.emplace_back(node->val);
      v[sz] += dfs(node->left, v) + dfs(node->right, v);
      return v[sz];
    }
    int maxProduct(TreeNode* root) {
      long long ans = 0;
      vector<int> v;
      dfs(root, v);
      for (int i = 0; i < v.size(); i++) 
        ans = max(ans, (long long) v[i] * (v[0] - v[i]));
      return ans % mod;
    }
};