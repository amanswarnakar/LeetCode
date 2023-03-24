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
    TreeNode *build(vector<int> &v, int l, int r){
      if(l > r) return NULL;
      int mid = l + (r - l) / 2; 
      TreeNode *root = new TreeNode(v[mid]);
      root->left = build(v, l, mid - 1);
      root->right = build(v, mid + 1, r);
      return root;
    }
  
    TreeNode* sortedArrayToBST(vector<int>& v) {
      int n = v.size(), l = 0, r = n - 1;
      return build(v, l, r);
    }
};