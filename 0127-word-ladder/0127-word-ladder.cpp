class Solution {
public:
  int ladderLength(string start, string end, vector<string>& words) {
    set<string> vis(words.begin(), words.end());
    queue<pair<string, int>> q;
    q.emplace(start, 1);
    vis.erase(start);
    while(!q.empty()){
      auto top = q.front();
      q.pop();
      string word = top.first;
      int ans = top.second;
      if(word == end) return ans;
      for(int i = 0; i < word.size(); i++){
        char ch = word[i];
        for(int j = 0; j < 26; j++){
          word[i] = 'a' + j;
          if(vis.find(word) != vis.end()){
            q.emplace(word, ans + 1);
            vis.erase(word);
          }
        }
        word[i] = ch;
      }
    }
    return 0;
  }
};