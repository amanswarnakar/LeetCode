class Solution {
public:
    bool checkPalindrome(string s, int l, int r){
      while(l < r){
        if(s[l++] != s[r--]) return false;
      }
      return true;
    }
    void recur(int i, string s, vector<string> &temp, vector<vector<string>> &ans){
      if(i == s.size()){
        ans.emplace_back(temp);
        return;
      }
      for(int idx = i; idx < s.size(); idx++){
        if(checkPalindrome(s, i, idx)){
          temp.emplace_back(s.substr(i, idx - i + 1));
          recur(idx + 1, s, temp, ans);
          temp.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> temp;
      recur(0, s, temp, ans);
      return ans;
    }
};