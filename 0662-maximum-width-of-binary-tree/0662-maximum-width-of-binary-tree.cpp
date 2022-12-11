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
    int widthOfBinaryTree(TreeNode* root) {
      if(!root) return 0;
      long ans = 0;
      queue<pair<TreeNode *, int>> q;
      q.push({root, 0});
      while(!q.empty()){
        long sz = q.size(), mini = q.front().second, idx, l, r;
        for(int i = 0; i < sz; i++){
          auto top = q.front(); q.pop();
          TreeNode *node = top.first;
          idx = top.second - mini;
          if(i == 0) l = idx;
          if(i == sz - 1) r = idx;
          if(node->left) q.push({node->left, (idx) * 2 + 1});
          if(node->right) q.push({node->right, (idx) * 2 + 2});
        }
        ans = max(ans, r - l + 1);
      }
      return ans;
    }
};