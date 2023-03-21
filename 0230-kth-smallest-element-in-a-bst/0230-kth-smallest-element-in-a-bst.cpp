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
    // void inorder(vector<int> &v, TreeNode *node){
    //   if(!node) return;
    //   if(node->left) inorder(v, node->left);
    //   v.emplace_back(node->val);
    //   if(node->right) inorder(v, node->right);
    // }
    
    int kthSmallest(TreeNode* root, int k) {
      stack<TreeNode *> st;
      while(true){
        while(root != NULL){
          st.push(root);
          root = root->left;
        }
        root = st.top(); st.pop();
        --k;
        if(k == 0) return root->val;
        root = root->right;
      }
      // return 0;
      
      // vector<int> v;
      // inorder(v, root);
      // return v[k - 1];
    }
};