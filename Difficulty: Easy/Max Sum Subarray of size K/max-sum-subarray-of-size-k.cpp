class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i=0,j=0,n=arr.size();
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans=max(ans,sum);
                j++;
            }
            else{
                while(j-i+1 > k){
                    sum-=arr[i];
                    i++;
                }
                if(j-i+1==k){
                    ans=max(ans,sum);
                }
                j++;
            }
        }
        return ans;
    }
};