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
    void dfs(TreeNode* node, int level, vector<double> &res, vector<double> &count){
      if(node == nullptr) return;
      if(level >= res.size()){
        res.push_back(node->val);
        count.push_back(1);
      } else {
        res[level] += node->val;
        count[level]++;
      }
      dfs(node->left, level+1, res, count);
      dfs(node->right, level+1, res, count);
    }
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double> ans, count, res;
      dfs(root, 0, res, count);
      for(int i = 0; i < res.size(); i++){
        ans.push_back(res[i] / count[i]);
      }
      return ans;
    }
};