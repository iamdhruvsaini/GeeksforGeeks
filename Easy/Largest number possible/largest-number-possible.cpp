//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int s){
        // code here
        if(N>1 && s==0)return "-1";
        string ans;
        for(int i=0;i<N;i++){
            if(s-9>=0){
                ans=ans+'9';
                s=s-9;
            }
            else if(s>0){
                char ch='0'+s;
                ans=ans+ch;
                s=0;
            }
            else{
                ans=ans+'0';
            }
        }
        if(s!=0)return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends