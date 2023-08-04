  int solve(int n,int k,vector<vector<int>>&dp){
        if(n==1){
            return k;
        }
        if(k==0||k==1){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int res;
        int ans=INT_MAX;
        
        for(int i=1;i<=k;i++){
            res=max(solve(n-1,i-1,dp),solve(n,k-i,dp));
            ans=min(ans,res);
        }
        dp[n][k]=ans+1;
        return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
