class Solution {
public:
      vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;
        for(string &s: strs){
          string temp = s;
          sort(temp.begin(), temp.end());
          um[temp].push_back(s);
        }
        for(auto &p: um){
          ans.push_back(p.second);
        }
        return ans;
      }
  
    // map<char, int> helper(string s){
    //   map<char, int> mp;
    //   for(char ch: s){
    //     mp[ch]++;
    //   }
    //   return mp;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //   map<map<char, int>, vector<string>> mp;
    //   vector<vector<string>> ans;
    //   for(string s: strs){
    //     mp[helper(s)].push_back(s);
    //   }
    //   for(auto p: mp){
    //     ans.push_back(p.second);
    //   }
    //   return ans;
    // }
};