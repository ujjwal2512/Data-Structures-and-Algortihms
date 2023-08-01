bool solve(vector<int>&nums,int sum,int idx,vector<vector<int>>&dp){
  
    if(sum==0){
        return true;
    }
      if (idx == 0 && sum != 0)
        return false;

    if(dp[sum][idx]!=-1){
        return dp[sum][idx];
    }

    if(sum>=nums[idx-1]){
        return dp[sum][idx]=solve(nums,sum-nums[idx-1],idx-1,dp)||solve(nums,sum,idx-1,dp);}

    return solve(nums,sum,idx-1,dp);
    

}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return 0;
        vector<vector<int>>dp(sum+1,vector<int>(nums.size()+1,-1));
        return solve(nums,sum/2,nums.size(),dp);
    }
