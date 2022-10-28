class Solution {
public:
  vector<string> helper(string s, int idx){
    vector<string> res;
    string temp = s;
    if(temp[idx] == '9') temp[idx] = '0';
    else temp[idx]++;
    res.emplace_back(temp);
    temp = s;
    if(temp[idx] == '0') temp[idx] = '9';
    else temp[idx]--;
    res.emplace_back(temp);
    return res;
  }
  int openLock(vector<string>& dead, string t) {
    queue<pair<string, int>> q;
    unordered_set<string> st;
    if(find(dead.begin(), dead.end(), "0000") != dead.end())
      return -1;
    for(auto s: dead)
      st.insert(s);
    q.emplace("0000", 0);
    st.insert("0000");
    while(!q.empty()){
      auto top = q.front();
      q.pop();
      string node = top.first;
      int ans = top.second;
      if(node == t) return ans;
      for(int i = 0; i < 4; i++){
        for(auto str: helper(node, i)){
          if(!st.count(str)) q.emplace(str, ans + 1), st.insert(str);
        }
      }
    }
    return -1;
  }
};