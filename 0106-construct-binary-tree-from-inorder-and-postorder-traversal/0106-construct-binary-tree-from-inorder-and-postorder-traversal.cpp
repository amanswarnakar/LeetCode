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
    TreeNode *builder(vector<int> &in, vector<int> &post, int start, int end, int &rootIdx){
      if(start > end) return NULL;
      TreeNode *node = new TreeNode(post[rootIdx--]);
      int idx = find(in.begin(), in.end(), node->val) - in.begin();
      // cout<<node->val<<" "<<start<<" "<<idx<<" "<<end<<endl;
      node->right = builder(in, post, idx + 1, end, rootIdx);
      node->left = builder(in, post, start, idx - 1, rootIdx);
      return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
      int n = inorder.size(), rootIdx = n - 1;
      return builder(inorder, postorder, 0, n - 1, rootIdx);
    }
};