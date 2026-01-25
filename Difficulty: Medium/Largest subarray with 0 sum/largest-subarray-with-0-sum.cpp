class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size(),ans=0,sum=0;
        vector<int>prefix(n,0);
        prefix[0]=arr[0];
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mp.find(sum)==mp.end()){
                // it not exists
                mp[sum]=i;
            }else{
                ans=max(ans,i-mp[sum]);
            }
        }
        return ans;
        
        
        
        // now find the respective entry
        
        
    }
};