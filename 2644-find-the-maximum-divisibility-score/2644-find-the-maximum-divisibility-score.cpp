class Solution {
public:
    int maxDivScore(vector<int>& v, vector<int>& div) {
      int ans = 0, maxx = 0;
      sort(div.begin(), div.end(), greater<int>());
      for(int i = 0; i < div.size(); i++){
        int temp = 0;
        for(int j = 0; j < v.size(); j++){
          if(v[j] % div[i] == 0) temp++;
        }
        if(temp >= maxx) ans = div[i];
        maxx = max(maxx, temp);
      }
      return ans;
    }
};