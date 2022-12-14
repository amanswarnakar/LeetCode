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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(!p and q) return false;
      if(p and !q) return false;
      if(!p and !q) return true;
      if(p and q and p->val != q->val) return false;
      bool left = isSameTree(p->left, q->left);
      bool right = isSameTree(p->right, q->right);
      return left and right;
    }
};