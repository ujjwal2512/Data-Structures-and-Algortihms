int solve(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
    if(i==s1.length()||j==s2.length()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        dp[i][j]=1+solve(s1,s2,i+1,j+1,dp);
        return dp[i][j];
    }else{
    int out1=0+solve(s1,s2,i,j+1,dp);
    int out2=0+solve(s1,s2,i+1,j,dp);
    dp[i][j]=max(out1,out2);
    return dp[i][j];
    }
}

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return solve(text1,text2,0,0,dp);
        
    }
