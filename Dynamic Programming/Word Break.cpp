bool solve(int idx,string s,set<string>&st,vector<int>&dp){
    if(idx==s.length()){
        return 1;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    string temp="";
    for(int i=idx;i<s.length();i++){
        temp+=s[i];
        if(st.find(temp)!=st.end()){
            if(solve(i+1,s,st,dp)){
                dp[idx]=1;
                return dp[idx];
            }
        }
    }
    dp[idx]=0;
    return dp[idx];

}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        vector<int>dp(s.length()+1,-1);
        return solve(0,s,st,dp);
    }
