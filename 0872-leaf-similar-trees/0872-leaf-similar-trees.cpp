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
    void traverse(TreeNode *root, vector<int> &v){
      if(root->left == NULL and root->right == NULL){
        v.push_back(root->val);
        return; 
      }
      if(root->left)  traverse(root->left, v);
      if(root->right) traverse(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int> v1, v2;
      traverse(root1, v1);
      traverse(root2, v2);
      return v1 == v2;
    }
};