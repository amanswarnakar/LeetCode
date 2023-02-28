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
    string postOrderTraverse(TreeNode *node, vector<TreeNode *> &ans, map<string, int> &mp){
      if(!node) return "#";
      string left = postOrderTraverse(node->left, ans, mp);
      string right = postOrderTraverse(node->right, ans, mp);
      string val = left + "-" + right + "-" + to_string(node->val);
      if(mp.find(val) != mp.end() and mp[val] == 1)
        ans.emplace_back(node);
      mp[val]++;
      return val;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      vector<TreeNode *> ans;
      map<string, int> mp;
      postOrderTraverse(root, ans, mp);
      for(auto &[f, s]: mp){
        cout<<f<<" "<<s<<endl;
      }
      return ans;
    }
};