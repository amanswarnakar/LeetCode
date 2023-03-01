class Solution {
public:
    void recur(string s, string temp, vector<bool> &vis, vector<string> &ans, int &cnt, int k){
      if(temp.size() == s.size()){
        ans.emplace_back(temp);
        cnt++;
        if(cnt == k) return;
      }
      for(int i = 0; i < s.size(); i++){
        if(!vis[i]){
          vis[i] = true;
          temp += s[i];
          recur(s, temp, vis, ans, cnt, k);
          temp.pop_back();
          vis[i] = false;
        }
        if(cnt == k) return;
      }
    }
    string getPermutation(int n, int k) {
      vector<string> ans;
      string s = "", temp = "";
      for(int i = 1; i < n + 1; i++)
        s += to_string(i);
      vector<bool> vis(n, false);
      int cnt = 0;
      recur(s, temp, vis, ans, cnt, k);
      return ans.back();
    }
};