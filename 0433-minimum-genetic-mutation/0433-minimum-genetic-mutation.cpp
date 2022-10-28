class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      queue<pair<string, int>> q;
      unordered_set<string> seen;
      q.emplace(start, 0);
      seen.insert(start);
      while(!q.empty()){
        auto top = q.front();
        q.pop();
        string node = top.first;
        int ans = top.second;
        if(node == end) return ans;
        for(auto ch: "ACGT"){
          for(int i = 0; i < 8; i++){
            string temp = node;
            temp[i] = ch;
            if(find(bank.begin(), bank.end(), temp) != bank.end() and !seen.count(temp)){
              q.emplace(temp, ans + 1);
              seen.insert(temp);
            }
          }
        }
      }
      return -1;
    }
};