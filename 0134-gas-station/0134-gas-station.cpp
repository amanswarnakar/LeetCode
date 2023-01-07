class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      // TC - O(n)
      int n = gas.size();
      int ans = 0, totalCost = accumulate(cost.begin(), cost.end(), 0), totalFuel = accumulate(gas.begin(), gas.end(), 0);
      if(totalFuel < totalCost) return -1;
      int fuel = 0, start = 0;
      for(int i = 0; i < n; i++){
        if(fuel < 0) start = i, fuel = 0;
        fuel += gas[i] - cost[i];
      }
      return start;
      
      // Brute Force TLE - TC - O(n^2)
      
      // int n = gas.size();
      // int ans = 0;
      // for(int i = 0; i < n; i++){
      //   gas.push_back(gas[i]);
      //   cost.push_back(cost[i]);
      // }
      // bool flag = false;
      // for(int i = 0; i < n; i++){
      //   int x = 0;
      //   for(int j = i; j < i + n; j++){
      //     x += gas[j] - cost[j];
      //     if(x < 0){
      //       flag = false;
      //       break;
      //     } else flag = true;
      //   }
      //   if(flag) return i;
      // }
      // return -1;
    }
};