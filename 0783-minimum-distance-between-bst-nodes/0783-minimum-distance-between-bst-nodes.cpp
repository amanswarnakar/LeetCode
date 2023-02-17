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
    void traverse(TreeNode *node, vector<int> &v){
      if(!node) return;
      if(node->left) traverse(node->left, v);
      v.emplace_back(node->val);
      if(node->right) traverse(node->right, v);
    }
    int minDiffInBST(TreeNode* root) {
      vector<int> v;
      traverse(root, v);
      int ans = INT_MAX;
      for(int i = 0; i < v.size() - 1; i++){
        ans = min(v[i + 1] - v[i], ans);
      }
      return ans;
    }
};