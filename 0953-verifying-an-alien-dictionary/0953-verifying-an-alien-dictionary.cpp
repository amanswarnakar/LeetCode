class Solution {
public:
    vector<int> mp;
    bool comp(string &a, string &b){
      int i = 0;
      while(i < a.size() and i < b.size()){
        if(a[i] == b[i]) {
          i++;
          continue;
        }
        else if(mp[a[i] - 'a'] > mp[b[i] - 'a']) return false;
        else return true;
        // i++;
      }
      return a.size() <= b.size();
    }
    bool isAlienSorted(vector<string>& words, string alphaOrder) {
      mp.resize(26);
      for(int i = 0; i < 26; i++){
        mp[alphaOrder[i] - 'a'] = i;
      }
      for(int i = 0; i < words.size() - 1; i++){
        if(!comp(words[i], words[i + 1])) return false;
      }      
      return true;
    }
};