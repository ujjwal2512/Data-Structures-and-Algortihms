int solve(string& w1,string& w2,int idx1,int idx2,vector<vector<int>>& dp){
    if(idx1==w1.length()){
        return w2.length()-idx2;
    }
    if(idx2==w2.length()){
        return w1.length()-idx1;
    }
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }
    if(w1[idx1]==w2[idx2]){
        return solve(w1,w2,idx1+1,idx2+1,dp);
    }
    int in=1+solve(w1,w2,idx1,idx2+1,dp);
    int del=1+solve(w1,w2,idx1+1,idx2,dp);
    int re=1+solve(w1,w2,idx1+1,idx2+1,dp);

    int ans=min(in,del);
    dp[idx1][idx2]=min(ans,re);

    return dp[idx1][idx2];
}
    int minDistance(string word1, string word2) {
       vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
