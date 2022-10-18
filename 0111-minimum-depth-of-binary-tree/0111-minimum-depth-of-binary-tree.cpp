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
    void traverse(TreeNode *root, int &ans, int temp = 0){
      temp++;
      if(root->left == nullptr and root->right == nullptr){
        ans = min(ans, temp);
        // cout<<root->val<<" "<<temp<<" "<<ans<<endl;
        return;
      }
      if(root->left) traverse(root->left, ans, temp);
      if(root->right) traverse(root->right, ans, temp);
    }
    int minDepth(TreeNode* root) {
      if(!root) return 0;
      int ans = INT_MAX;
      traverse(root, ans);
      return ans;
    }
};