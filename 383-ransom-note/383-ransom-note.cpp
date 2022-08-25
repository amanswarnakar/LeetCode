class Solution {
public:
    bool canConstruct(string rn, string magazine) {
      map<char, int> mp_mag;
      for(char s: magazine){
        mp_mag[s]++;
      }
      for(int i = 0; i < rn.size(); i++){
        if(mp_mag.find(rn[i]) != mp_mag.end()){
          if(mp_mag[rn[i]] > 0) mp_mag[rn[i]]--;
          else return false;
        } else {
          return false;
        }
      }
      return true;
    }
};