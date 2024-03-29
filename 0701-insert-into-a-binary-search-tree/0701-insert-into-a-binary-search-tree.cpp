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
    TreeNode* insertIntoBST(TreeNode* root, int val, TreeNode *parentNode = NULL) {
      // Recursive DFS
      
      if(!root) return new TreeNode(val);
      if(root->val > val) root->left = insertIntoBST(root->left, val);
      else root->right = insertIntoBST(root->right, val);
      return root;
      
      // Iterative BFS
      
      // if(!root) return new TreeNode(val);
      // TreeNode *curr = root;
      // while(true){
      //   if(val < curr->val){
      //     if(curr->left) curr = curr->left;
      //     else{
      //       curr->left = new TreeNode(val);
      //       break;
      //     }
      //   } else {
      //     if(curr->right) curr = curr->right;
      //     else{
      //       curr->right = new TreeNode(val);
      //       break;
      //     } 
      //   }
      // }
      // return root;
    }
};