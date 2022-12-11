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
    int maxDepth(TreeNode* root) {
      // DFS
      
      if(!root) return 0;
      int left = maxDepth(root->left);
      int right = maxDepth(root->right);
      return max(left, right) + 1;
      
      // BFS
      
//       if(!root) return 0;
//       int ans = 0;
//       queue<TreeNode *> q;
//       q.emplace(root);
//       while(!q.empty()){
//         int sz = q.size();
//         for(int i = 0; i < sz; i++){
//           auto qf = q.front(); q.pop();
//           if(qf->left) q.emplace(qf->left);
//           if(qf->right) q.emplace(qf->right);
//         }
//         ans++;
//       }
//       return ans;
    }
};