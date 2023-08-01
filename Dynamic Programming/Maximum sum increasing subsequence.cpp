int solve(int arr[],int n,int idx,int prev,vector<vector<int>>&dp){
	    if(idx==n){
	        return 0;
	    }
	    if(dp[idx][prev+1]!=-1){
	        return dp[idx][prev+1];
	    }
	    int in=0;
	    if(prev==-1||arr[idx]>arr[prev]){
	        in=arr[idx]+solve(arr,n,idx+1,idx,dp);
	    }
	    int out=solve(arr,n,idx+1,prev,dp);
	    
	    dp[idx][prev+1]=max(in,out);
	    return dp[idx][prev+1];
	    
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return solve(arr,n,0,-1,dp);
	}  
