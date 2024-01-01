//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
         unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i]%k;
            int need=k-curr;
            need=need%k;
            
            if(mp.count(need)){
                mp[need]--;
                if(mp[need]==0){
                    mp.erase(need);
                    
                }
            }
            else{
                mp[curr]++;
            }
            
        }
        return mp.size()==0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends