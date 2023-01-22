class Solution {
public:
    bool checkPalindrome(string s, int l, int r){
      while(l < r){
        if(s[l] != s[r]) return false;
        l++; r--;
      }
      return true;
    }
    void helper(string s, int idx, vector<string> &v, vector<vector<string>> &ans){
      if(idx == s.size()){
        ans.emplace_back(v);
        return;
      }
      for(int i = idx; i < s.size(); i++){
        if(checkPalindrome(s, idx, i)){
          v.push_back(s.substr(idx, i - idx + 1));
          helper(s, i + 1, v, ans);
          v.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> v;
      helper(s, 0, v, ans);
      return ans;
    }
};