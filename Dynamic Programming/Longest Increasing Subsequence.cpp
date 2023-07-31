int solve(vector<int>& nums,int idx,int prev,vector<vector<int>>& dp){
    int n=nums.size();
    if(idx==n){
        return 0;
    }
    if(dp[idx][prev+1]!=-1){
        return dp[idx][prev+1];
    }
    int in=0;
    if(prev==-1||nums[idx]>nums[prev]){
        in=1+solve(nums,idx+1,idx,dp);
    }
    int out=0+solve(nums,idx+1,prev,dp);

    dp[idx][prev+1]=max(in,out);
    return dp[idx][prev+1];


}
    int lengthOfLIS(vector<int>& nums) {
       vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
       return solve(nums,0,-1,dp);
        
    }
