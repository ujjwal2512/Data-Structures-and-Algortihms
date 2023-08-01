 int solve(vector<int>&coins,int target,int idx,vector<vector<int>>&dp){
      if(idx==0){
          if(target%coins[idx]==0){
              return target/coins[idx];
          }else{
              return 1e9;
          }
      }
      if(dp[target][idx]!=-1){
          return dp[target][idx];
      }
      int out=0+solve(coins,target,idx-1,dp);
      int in=INT_MAX;
      if(target>=coins[idx]){
          in=1+solve(coins,target-coins[idx],idx,dp);
      }
      dp[target][idx]=min(in,out);
      return dp[target][idx];
  }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
       int ans=solve(coins,amount,coins.size()-1,dp); 
       if(ans>=1e9){
        return -1;
       }else{
           return ans;
       }
        
    }
