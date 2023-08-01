    int solve(int W,int wt[],int val[],int n,int idx,vector<vector<int>>&dp){
        if(idx==n){
            return 0;
        }
        if(dp[W][idx]!=-1){
            return dp[W][idx];
        }
        int in=0;
        if(wt[idx]<=W){
            in=val[idx]+solve(W-wt[idx],wt,val,n,idx+1,dp);
        }
        int out=0+solve(W,wt,val,n,idx+1,dp);
        dp[W][idx]= max(in,out);
        return dp[W][idx];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return solve(W,wt,val,n,0,dp);
    }
