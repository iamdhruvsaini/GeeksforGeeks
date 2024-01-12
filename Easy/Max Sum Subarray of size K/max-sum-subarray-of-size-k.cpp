//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
    
        long long ans=INT_MIN;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        ans=max(ans,sum);
        int j=k;
        int i=0;
        while(j<n){
            sum=sum-arr[i]+arr[j];
            ans=max(sum,ans);
            j++;
            i++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends