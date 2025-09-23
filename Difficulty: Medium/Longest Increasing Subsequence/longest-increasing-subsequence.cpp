class Solution {
  public:
    
    int solve(vector<int>& arr,int index,int prev,vector<vector<int>>&dp){
        if(index==arr.size())return 0;
        
        
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];    
        }
        
        int left=0;
        if(prev==-1 || arr[index]>arr[prev]){
            left=1+solve(arr,index+1,index,dp);
        }
        
        int right=0+solve(arr,index+1,prev,dp);
    
        
        return dp[index][prev+1]=max(left,right);
        
        
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
    
        return solve(arr,0,-1,dp);
        
    }
};