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
    void inorder(TreeNode *root, vector<int> &v){
      if(!root) return;
      inorder(root->left, v);
      v.push_back(root->val);
      inorder(root->right, v);
    }
    
    bool findTarget(TreeNode* root, int k) {
      // Two Sum Approach with a vector
      vector<int> v;
      inorder(root, v);
      // for(auto i: v) cout<<i<<" ";
      // sort(v.begin(), v.end());
      int l = 0, r = v.size() - 1;
      while(l < r){
        if(v[l] == k - v[r]) return true;
        else if(v[l] < k - v[r]) l++;
        else r--;
      }
      return false;
    }
};