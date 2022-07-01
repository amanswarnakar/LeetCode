class Solution {
public:
    void bubbleSort2D(vector<vector<int>> &a, int n){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
          if(a[j][1] < a[j+1][1]){
            swap(a[j][1], a[j+1][1]);
            swap(a[j][0], a[j+1][0]);
          }
        }
      }
    }
  
    static bool comp(vector<int> sec, vector<int> fir)
    {
      if(sec.back()>fir.back())
        return true;
      else if(sec.back()==fir.back() and sec.front()>fir.front())
      {
        return true;
      }
      else return false;
    }
    int maximumUnits(vector<vector<int>>& bt, int ts) {    // bt: boxTypes, ts: truckSize
      int n = bt.size(); 
      sort(bt.begin(),bt.end(),comp);
      int sum = 0, l = 0;
      while(l < n){
        if(ts >= bt[l][0]){
          sum += bt[l][0] * bt[l][1];
          ts -= bt[l][0];
        } else {
          sum += ts * bt[l][1];
          break;
        }
        l++;
      }
      return sum;
    }
};