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
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      queue<TreeNode *> q;
      q.emplace(root);
      int ans = 0;
      while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          auto node = q.front();
          q.pop();
          ans++;
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
        }
      }
      return ans;
    }
};