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
  /*
    bool dfs(TreeNode *node){
            
    }
  */
    bool isCompleteTree(TreeNode* root) {
      if(!root) return true;
      queue<TreeNode *> q;
      q.emplace(root);
      bool flag = false;
      while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          auto node = q.front(); q.pop();
          if(!node) flag = true;
          else {
            if(flag) return false;
            q.emplace(node->left);
            q.emplace(node->right);
          }
        }
      }
      return true;
    }
};