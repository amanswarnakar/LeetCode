class Solution {
public:
    int firstUniqChar(string s) {
      map<char, int> mp;
      for(char ch : s){
        mp[ch]++;
      }
      for(int i = 0; i < s.size(); i++){
        if(mp[s[i]] == 1) return i;
      }
      return -1;
    }
};