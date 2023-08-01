int solve(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==n&&j==m){
        return 0;
    }
    if(i==n-1&&j==m-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int d=INT_MAX;
    if(i+1<n){
    d=grid[i][j]+solve(grid,i+1,j,n,m,dp);}
    int r=INT_MAX;
    if(j+1<m){
    r=grid[i][j]+solve(grid,i,j+1,n,m,dp);}

    dp[i][j]=min(d,r);
    return dp[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,0,0,n,m,dp);
    }
