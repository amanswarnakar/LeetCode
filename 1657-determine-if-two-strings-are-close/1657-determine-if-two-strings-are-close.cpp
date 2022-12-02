class Solution {
public:
    bool closeStrings(string word1, string word2) {
      if(word1.size() != word2.size()) return false;
      unordered_map<char, int> um1, um2;
      vector<int> p, q;
      unordered_set<char> s1, s2;
      for(auto &i: word1){
        um1[i]++;
        s1.insert(i);
      }
      for(auto &i: word2){
        um2[i]++;
        s2.insert(i);
      }
      for(auto &pr: um1){
        p.emplace_back(pr.second);
      }
      for(auto &pr: um2){
        q.emplace_back(pr.second);
      }
      sort(p.begin(), p.end());
      sort(q.begin(), q.end());
      return p == q and s1 == s2;
    }
};