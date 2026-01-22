class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
       int i=0;
       int j=0;
       int n=arr.size();
       int sum=0,ans=INT_MIN;
       
       while(j<n){
           if(j-i+1 < k){
               sum+=arr[j];
               j++;
           }
           else if(j-i+1 == k){
               sum+=arr[j++];
               ans=max(ans,sum);
               sum-=arr[i++];
              
           }
       }
       return ans;
        
    }
};