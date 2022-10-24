class Solution {
public:
    bool canConstruct(string rn, string magazine) {
      map<char, int> mp;
      for(char s: magazine) mp[s]++;
      for(int i = 0; i < rn.size(); i++){
        if(mp.find(rn[i]) != mp.end() and mp[rn[i]] > 0) mp[rn[i]]--;
        else return false;
      }
      return true;
    }
};