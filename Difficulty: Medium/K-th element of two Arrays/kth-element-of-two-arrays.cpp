//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1=a.size();
        int n2=b.size();
      
        if(n1>n2){
            return kthElement(b,a,k);
        }
        
        int s=max(0,k-n2),e=min(n1,k);
        
        while(s<=e){
            int mid1=s+(e-s)/2;
            int mid2=k-mid1;
            
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            
            if(mid1<n1)r1=a[mid1];
            if(mid2<n2)r2=b[mid2];
            
            if(mid1-1 >= 0)l1=a[mid1-1];
            if(mid2-1 >= 0)l2=b[mid2-1];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                e=mid1-1;
            }
            else{
                s=mid1+1;
            }
        }
        return -1;
        
        

    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends