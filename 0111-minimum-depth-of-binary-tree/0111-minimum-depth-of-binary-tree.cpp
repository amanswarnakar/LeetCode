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
    void dfs(TreeNode *root, int &ans, int temp = 0){
      temp++;
      if(root->left == nullptr and root->right == nullptr){
        ans = min(ans, temp);
        return;
      }
      if(root->left) dfs(root->left, ans, temp);
      if(root->right) dfs(root->right, ans, temp);
    }
    int minDepth(TreeNode* root) {
      if(!root) return 0;
      
      // DFS
      // int ans = INT_MAX;
      // dfs(root, ans);
      
      // BFS
      int ans = 0;
      queue<TreeNode *> q;
      q.push(root);
      while(!q.empty()){
        int s = q.size();
        ans++;
        for(int i = 0; i < s; i++){
          TreeNode *temp = q.front();
          q.pop();
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
          if(temp->left == NULL and temp->right == NULL)  return ans;
        }
      }
      
      return ans;
    }
};